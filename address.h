#pragma once

namespace pkodev
{
	namespace address
	{
        // GameServer.exe 1.36
        namespace GAMESERVER_136
        {
            // BOOL CGameApp::Init()
            const unsigned int CGameApp__Init = 0x00490D40;

            // operator new
            const unsigned int operator_new = 0x00561BD5;

            // CPicSet::CPicSet()
            const unsigned int CPicSet__CPicSet = 0x00511BB0;

            // bool CPicSet::init()
            const unsigned int CPicSet__init = 0x00511D70;

            // void LG2(char const* type, char const* format, ...)
            const unsigned int LG2 = 0x005345C0;

            // void CCharacter::Run(DWORD dwCurTime) 
            const unsigned int CCharacter__Run = 0x004E3A30;

            // void CCharacter::ProcessPacket(unsigned short usCmd, RPACKET pk)
            const unsigned int CCharacter__ProcessPacket = 0x004DDC50;

            // void CCharacter::CheatRun(DWORD dwCurTime)
            const unsigned int CCharacter__CheatRun = 0x004D2550;

            // void CCharacter::CheatCheck(cChar *answer)
            const unsigned int CCharacter__CheatCheck = 0x004D28C0;

            // bool CCharacter::IsPlayerCha()
            const unsigned int CCharacter__IsPlayerCha = 0x004BC450;

            // bool CCharacter::IsGMCha2()
            const unsigned int CCharacter__IsGMCha2 = 0x004BC6A0;

            // dbc::uShort Entity::GetAreaAttr()
            const unsigned int Entity__GetAreaAttr = 0x00444F90;

            // bool	CCharacter::IsBoat()
            const unsigned int CCharacter__IsBoat = 0x00416B40;

            // CCharacter* CCharacter::GetPlyCtrlCha()
            const unsigned int CCharacter__GetPlyCtrlCha = 0x004BC5B0;

            // CCharacter* CCharacter::GetPlyMainCha()
            const unsigned int CCharacter__GetPlyMainCha = 0x004BC5F0;

            // SubMap* Entity::GetSubMap()
            const unsigned int Entity__GetSubMap = 0x00416830;

            // CMapRes*	SubMap::GetMapRes()
            const unsigned int SubMap__GetMapRes = 0x0041B490;

            // bool	CMapRes::CanPK()
            const unsigned int CMapRes__CanPK = 0x004B6050;

            // bool CPlayer::IsValid()
            const unsigned int CPlayer__IsValid = 0x00480C30;

            // cChar *RPacket::ReadString(uShort *len)
            const unsigned int RPacket__ReadString = 0x0051A9C0;

            // DWORD CCharacter::GetCheatInterval(int state)
            const unsigned int CCharacter__GetCheatInterval = 0x004D2480;
        }

        // GameServer.exe 1.38
        namespace GAMESERVER_138
        {
            // BOOL CGameApp::Init()
            const unsigned int CGameApp__Init = 0x004981A0;

            // operator new
            const unsigned int operator_new = 0x0056E0B5;

            // CPicSet::CPicSet()
            const unsigned int CPicSet__CPicSet = 0x0051AEC0;

            // bool CPicSet::init()
            const unsigned int CPicSet__init = 0x0051B080;

            // void LG2(char const* type, char const* format, ...)
            const unsigned int LG2 = 0x0053D950;

            // void CCharacter::Run(DWORD dwCurTime) 
            const unsigned int CCharacter__Run = 0x004EC4E0;

            // void CCharacter::ProcessPacket(unsigned short usCmd, RPACKET pk)
            const unsigned int CCharacter__ProcessPacket = 0x004E62A0;

            // void CCharacter::CheatRun(DWORD dwCurTime)
            const unsigned int CCharacter__CheatRun = 0x004DA290;

            // void CCharacter::CheatCheck(cChar *answer)
            const unsigned int CCharacter__CheatCheck = 0x004DA610;

            // bool CCharacter::IsPlayerCha()
            const unsigned int CCharacter__IsPlayerCha = 0x004C39E0;

            // bool CCharacter::IsGMCha2()
            const unsigned int CCharacter__IsGMCha2 = 0x004C3C30;

            // dbc::uShort Entity::GetAreaAttr()
            const unsigned int Entity__GetAreaAttr = 0x00447A50;

            // bool	CCharacter::IsBoat()
            const unsigned int CCharacter__IsBoat = 0x00417D60;

            // CCharacter* CCharacter::GetPlyCtrlCha()
            const unsigned int CCharacter__GetPlyCtrlCha = 0x004C3B40;

            // CCharacter* CCharacter::GetPlyMainCha()
            const unsigned int CCharacter__GetPlyMainCha = 0x004C3B80;

            // SubMap* Entity::GetSubMap()
            const unsigned int Entity__GetSubMap = 0x00417A50;

            // CMapRes*	SubMap::GetMapRes()
            const unsigned int SubMap__GetMapRes = 0x0041C710;

            // bool	CMapRes::CanPK()
            const unsigned int CMapRes__CanPK = 0x004BD5D0;

            // bool CPlayer::IsValid()
            const unsigned int CPlayer__IsValid = 0x00484A10;

            // cChar *RPacket::ReadString(uShort *len)
            const unsigned int RPacket__ReadString = 0x00523D50;

            // DWORD CCharacter::GetCheatInterval(int state)
            const unsigned int CCharacter__GetCheatInterval = 0x004DA1C0;
        }
	}
}