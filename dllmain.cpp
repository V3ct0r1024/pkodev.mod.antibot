#include <Windows.h>
#include <detours.h>

#include "loader.h"

#include "address.h"
#include "pointer.h"
#include "hook.h"
#include "structure.h"

#include <iostream>


// Entry point
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    // Nothing to do . . .
    return TRUE;
}

// Get mod information
void GetModInformation(mod_info& info)
{
    strcpy_s(info.name, TOSTRING(MOD_NAME));
    strcpy_s(info.version, TOSTRING(MOD_VERSION));
    strcpy_s(info.author, TOSTRING(MOD_AUTHOR));
    info.exe_version = MOD_EXE_VERSION;
}

// Start the mod
void Start(const char* path)
{
    // Enable hooks
    DetourRestoreAfterWith();
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(PVOID&)pkodev::pointer::CGameApp__Init, pkodev::hook::CGameApp__Init);
    DetourAttach(&(PVOID&)pkodev::pointer::CCharacter__Run, pkodev::hook::CCharacter__Run);
    DetourAttach(&(PVOID&)pkodev::pointer::CCharacter__ProcessPacket, pkodev::hook::CCharacter__ProcessPacket);
    DetourAttach(&(PVOID&)pkodev::pointer::CCharacter__GetCheatInterval, pkodev::hook::CCharacter__GetCheatInterval);
    DetourTransactionCommit();

    // Print welcome message
    std::cout << "[" << TOSTRING(MOD_NAME) << "] Antibot system ver. " 
        << TOSTRING(MOD_VERSION) << " by " << TOSTRING(MOD_AUTHOR) << " enabled!" << std::endl;
}

// Stop the mod
void Stop()
{
    // Disable hooks
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourDetach(&(PVOID&)pkodev::pointer::CGameApp__Init, pkodev::hook::CGameApp__Init);
    DetourDetach(&(PVOID&)pkodev::pointer::CCharacter__Run, pkodev::hook::CCharacter__Run);
    DetourDetach(&(PVOID&)pkodev::pointer::CCharacter__ProcessPacket, pkodev::hook::CCharacter__ProcessPacket);
    DetourDetach(&(PVOID&)pkodev::pointer::CCharacter__GetCheatInterval, pkodev::hook::CCharacter__GetCheatInterval);
    DetourTransactionCommit();
}

// BOOL CGameApp::Init()
int __fastcall pkodev::hook::CGameApp__Init(void* This, void* NotUsed)
{
    // Call the original method BOOL CGameApp::Init()
    int ret = pkodev::pointer::CGameApp__Init(This);

    // Check the result
    if (ret != 0)
    {
        // Allocate some memory for CPicSet object
        void* pic_set_obj = pkodev::pointer::operator_new(0x34);

        // Check that memory is allocated
        if (pic_set_obj == nullptr)
        {
            // Error
            pkodev::pointer::LG2("init", "msgMemory allocation for the CPicSet object is failed!");
            return 0;
        }

        // Write the address of allocated memory to the CGameApp::m_PicSet member variable
        *reinterpret_cast<unsigned int*>(
            reinterpret_cast<unsigned int>(This) + 0x0C85B8
        ) = reinterpret_cast<unsigned int>(pic_set_obj);

        // Call the CPicSet::CPicSet() constructor
        pkodev::pointer::CPicSet__CPicSet(pic_set_obj);

        // Initialize the CPicSet object
        bool init = pkodev::pointer::CPicSet__init(pic_set_obj);

        // Check the result
        if (init == false)
        {
            // Error
            pkodev::pointer::LG2("init", "msgCPicSet::init() failed!");
            return 0;
        }
    }

    return ret;
}

// void CCharacter::Run(DWORD dwCurTime) 
void __fastcall pkodev::hook::CCharacter__Run(void* This, void* NotUsed,
    unsigned int dwCurTime)
{
    // Call the original method
    pkodev::pointer::CCharacter__Run(This, dwCurTime);

    // Get pointer to the CPlayer *CCharacter::m_pCPlayer member variable
    void* m_pCPlayer = reinterpret_cast<void*>(
        *reinterpret_cast<unsigned int*>(
            reinterpret_cast<unsigned int>(This) + 0x021C
        )
    );

    /*
        if (m_pCPlayer && !m_pCPlayer->IsValid())
            return;
    */
    if ( (m_pCPlayer != nullptr) && (pkodev::pointer::CPlayer__IsValid(m_pCPlayer) == false) )
    {
        return;
    }

    /*
 	    if (!GetSubMap())
		    return;
    */
    if (pkodev::pointer::Entity__GetSubMap(This) == nullptr)
    {
        return;
    }

    // Check that this character is a player's character
    if (pkodev::pointer::CCharacter__IsPlayerCha(This) == true)
    {
        // Check that the player is not GM
        if (pkodev::pointer::CCharacter__IsGMCha2(This) == true)
        {
            // Player shouldn't be GM
            return;
        }

        // Check that the player is not in the safe zone
        if ( (pkodev::pointer::Entity__GetAreaAttr(This) & 0x0002) == 0x0002 )
        {
            // Player is in the safe zone, check that his not in the boat
            if (pkodev::pointer::CCharacter__IsBoat(This) == false)
            {
                // Player shouldn't be in the safe zone or his should be in the boat
                return;
            }
        }

        // Get 'MapCanPK' flag
        bool map_can_pk = pkodev::pointer::CMapRes__CanPK(
            pkodev::pointer::SubMap__GetMapRes(
                pkodev::pointer::Entity__GetSubMap(
                    pkodev::pointer::CCharacter__GetPlyCtrlCha(This)
                )
            )
        );

        // Check that map, on which the player is located, is not PvP one
        if (map_can_pk == true)
        {
            // The antibot system doesn't work on PvP maps
            return;
        }

        // Process the antibot system timer
        pkodev::pointer::CCharacter__CheatRun(
            pkodev::pointer::CCharacter__GetPlyMainCha(This),
            dwCurTime
        );
    }
}

// void CCharacter::ProcessPacket(unsigned short usCmd, RPACKET pk)
void __fastcall pkodev::hook::CCharacter__ProcessPacket(void* This, void* NotUsed,
    unsigned short int usCmd, int a1, int a2, int a3, int a4, int a5, 
    int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13,
    int a14, int a15, int a16)
{
    // Build RPacket object from stack
    char rpacket[0x40]{ 0x00 };
    *reinterpret_cast<int*>(rpacket)     = a1;
    *reinterpret_cast<int*>(rpacket + 4) = a2;
    *reinterpret_cast<int*>(rpacket + 8) = a3;
    *reinterpret_cast<int*>(rpacket + 12) = a4;
    *reinterpret_cast<int*>(rpacket + 16) = a5;
    *reinterpret_cast<int*>(rpacket + 20) = a6;
    *reinterpret_cast<int*>(rpacket + 24) = a7;
    *reinterpret_cast<int*>(rpacket + 28) = a8;
    *reinterpret_cast<int*>(rpacket + 32) = a9;
    *reinterpret_cast<int*>(rpacket + 36) = a10;
    *reinterpret_cast<int*>(rpacket + 40) = a11;
    *reinterpret_cast<int*>(rpacket + 44) = a12;
    *reinterpret_cast<int*>(rpacket + 48) = a13;
    *reinterpret_cast<int*>(rpacket + 52) = a14;
    *reinterpret_cast<int*>(rpacket + 56) = a15;
    *reinterpret_cast<int*>(rpacket + 60) = a16;

    // Check that this is the answer packet for antibot
    if (usCmd == 52) // CMD_CM_CHEAT_CHECK
    {
        // Check the answer
        pkodev::pointer::CCharacter__CheatCheck(
            pkodev::pointer::CCharacter__GetPlyMainCha(This),
            pkodev::pointer::RPacket__ReadString(reinterpret_cast<void*>(rpacket), nullptr)
        );
    }
    else
    {
        // Call the original function CCharacter::ProcessPacket()
        pkodev::pointer::CCharacter__ProcessPacket(This, usCmd, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16);
    }
}

// DWORD CCharacter::GetCheatInterval(int state)
unsigned int __fastcall pkodev::hook::CCharacter__GetCheatInterval(void* This, void* NotUsed, int state)
{
    /*

        // Get SCheatX structure with the antibot data
        const SCheatX* cheat = reinterpret_cast<SCheatX*>(
            reinterpret_cast<unsigned int>(This) + 0x76C8
        );

        For custom timer: 

           When state = 1 then antibot window is showing.
           Time is in milliseconds.

         Example:

            if (state == 1)
            {
                return 65000; // 65 seconds to enter the code
            }
            else
            {
                return 5 * 60000; // 5 minutes antibot interval
            }

    */
    
    // Call the original method DWORD CCharacter::GetCheatInterval(int state)
    return pkodev::pointer::CCharacter__GetCheatInterval(This, state);
}