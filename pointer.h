#pragma once
#include "address.h"
#include "structure.h"

namespace pkodev
{
	namespace pointer
	{
        // BOOL CGameApp::Init()
        typedef int(__thiscall* CGameApp__Init__Ptr)(void*);
        CGameApp__Init__Ptr CGameApp__Init = (CGameApp__Init__Ptr)(void*)(address::MOD_EXE_VERSION::CGameApp__Init);

        // operator new
        typedef void*(__cdecl* operator_new__Ptr)(unsigned int);
        operator_new__Ptr operator_new = (operator_new__Ptr)(void*)(address::MOD_EXE_VERSION::operator_new);

        // CPicSet::CPicSet()
        typedef void(__thiscall* CPicSet__CPicSet__Ptr)(void*);
        CPicSet__CPicSet__Ptr CPicSet__CPicSet = (CPicSet__CPicSet__Ptr)(void*)(address::MOD_EXE_VERSION::CPicSet__CPicSet);

        // bool CPicSet::init()
        typedef bool(__thiscall* CPicSet__init__Ptr)(void*);
        CPicSet__init__Ptr CPicSet__init = (CPicSet__init__Ptr)(void*)(address::MOD_EXE_VERSION::CPicSet__init);

        // void LG2(char const* type, char const* format, ...)
        typedef void(__cdecl* LG2__Ptr)(const char*, const char*, ...);
        LG2__Ptr LG2 = (LG2__Ptr)(void*)(address::MOD_EXE_VERSION::LG2);

        // void CCharacter::Run(DWORD dwCurTime) 
        typedef void(__thiscall* CCharacter__Run__Ptr)(void*, unsigned int);
        CCharacter__Run__Ptr CCharacter__Run = (CCharacter__Run__Ptr)(void*)(address::MOD_EXE_VERSION::CCharacter__Run);

        // void CCharacter::ProcessPacket(unsigned short usCmd, RPACKET pk)
        typedef void(__thiscall* CCharacter__ProcessPacket__Ptr)(void*, unsigned short int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
        CCharacter__ProcessPacket__Ptr CCharacter__ProcessPacket = (CCharacter__ProcessPacket__Ptr)(void*)(address::MOD_EXE_VERSION::CCharacter__ProcessPacket);

        // void CCharacter::CheatRun(DWORD dwCurTime)
        typedef void(__thiscall* CCharacter__CheatRun__Ptr)(void*, unsigned int);
        CCharacter__CheatRun__Ptr CCharacter__CheatRun = (CCharacter__CheatRun__Ptr)(void*)(address::MOD_EXE_VERSION::CCharacter__CheatRun);

        // void CCharacter::CheatCheck(cChar *answer)
        typedef void(__thiscall* CCharacter__CheatCheck__Ptr)(void*, const char*);
        CCharacter__CheatCheck__Ptr CCharacter__CheatCheck = (CCharacter__CheatCheck__Ptr)(void*)(address::MOD_EXE_VERSION::CCharacter__CheatCheck);
	
        // bool CCharacter::IsPlayerCha()
        typedef bool(__thiscall* CCharacter__IsPlayerCha__Ptr)(void*);
        CCharacter__IsPlayerCha__Ptr CCharacter__IsPlayerCha = (CCharacter__IsPlayerCha__Ptr)(void*)(address::MOD_EXE_VERSION::CCharacter__IsPlayerCha);

        // bool CCharacter::IsGMCha2()
        typedef bool(__thiscall* CCharacter__IsGMCha2__Ptr)(void*);
        CCharacter__IsGMCha2__Ptr CCharacter__IsGMCha2 = (CCharacter__IsGMCha2__Ptr)(void*)(address::MOD_EXE_VERSION::CCharacter__IsGMCha2);

        // dbc::uShort Entity::GetAreaAttr()
        typedef unsigned short int(__thiscall* Entity__GetAreaAttr__Ptr)(void*);
        Entity__GetAreaAttr__Ptr Entity__GetAreaAttr = (Entity__GetAreaAttr__Ptr)(void*)(address::MOD_EXE_VERSION::Entity__GetAreaAttr);

        // bool	CCharacter::IsBoat()
        typedef bool(__thiscall* CCharacter__IsBoat__Ptr)(void*);
        CCharacter__IsBoat__Ptr CCharacter__IsBoat = (CCharacter__IsBoat__Ptr)(void*)(address::MOD_EXE_VERSION::CCharacter__IsBoat);

        // CCharacter* CCharacter::GetPlyCtrlCha()
        typedef void*(__thiscall* CCharacter__GetPlyCtrlCha__Ptr)(void*);
        CCharacter__GetPlyCtrlCha__Ptr CCharacter__GetPlyCtrlCha = (CCharacter__GetPlyCtrlCha__Ptr)(void*)(address::MOD_EXE_VERSION::CCharacter__GetPlyCtrlCha);

        // CCharacter* CCharacter::GetPlyMainCha()
        typedef void*(__thiscall* CCharacter__GetPlyMainCha__Ptr)(void*);
        CCharacter__GetPlyMainCha__Ptr CCharacter__GetPlyMainCha = (CCharacter__GetPlyMainCha__Ptr)(void*)(address::MOD_EXE_VERSION::CCharacter__GetPlyMainCha);

        // SubMap* Entity::GetSubMap()
        typedef void*(__thiscall* Entity__GetSubMap__Ptr)(void*);
        Entity__GetSubMap__Ptr Entity__GetSubMap = (Entity__GetSubMap__Ptr)(void*)(address::MOD_EXE_VERSION::Entity__GetSubMap);

        // CMapRes*	SubMap::GetMapRes()
        typedef void*(__thiscall* SubMap__GetMapRes__Ptr)(void*);
        SubMap__GetMapRes__Ptr SubMap__GetMapRes = (SubMap__GetMapRes__Ptr)(void*)(address::MOD_EXE_VERSION::SubMap__GetMapRes);

        // bool	CMapRes::CanPK()
        typedef bool(__thiscall* CMapRes__CanPK__Ptr)(void*);
        CMapRes__CanPK__Ptr CMapRes__CanPK = (CMapRes__CanPK__Ptr)(void*)(address::MOD_EXE_VERSION::CMapRes__CanPK);
        
        // bool CPlayer::IsValid()
        typedef bool(__thiscall* CPlayer__IsValid__Ptr)(void*);
        CPlayer__IsValid__Ptr CPlayer__IsValid = (CPlayer__IsValid__Ptr)(void*)(address::MOD_EXE_VERSION::CPlayer__IsValid);
    
        // cChar *RPacket::ReadString(uShort *len)
        typedef const char* (__thiscall* RPacket__ReadString__Ptr)(void*, unsigned short int*);
        RPacket__ReadString__Ptr RPacket__ReadString = (RPacket__ReadString__Ptr)(void*)(address::MOD_EXE_VERSION::RPacket__ReadString);

        // DWORD CCharacter::GetCheatInterval(int state)
        typedef unsigned int(__thiscall* CCharacter__GetCheatInterval__Ptr)(void*, int);
        CCharacter__GetCheatInterval__Ptr CCharacter__GetCheatInterval = (CCharacter__GetCheatInterval__Ptr)(void*)(address::MOD_EXE_VERSION::CCharacter__GetCheatInterval);
    }
}