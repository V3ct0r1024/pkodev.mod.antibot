#pragma once
#include "structure.h"

namespace pkodev
{
	namespace hook
	{
		// BOOL CGameApp::Init()
		int __fastcall CGameApp__Init(void* This, void* NotUsed);

		// // void CCharacter::Run(DWORD dwCurTime) 
		void __fastcall CCharacter__Run(void* This, void* NotUsed, unsigned int dwCurTime);

		// void CCharacter::ProcessPacket(unsigned short usCmd, RPACKET pk)
		void __fastcall CCharacter__ProcessPacket(void* This, void* NotUsed, unsigned short int usCmd, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16);
		
		// DWORD CCharacter::GetCheatInterval(int state)
		unsigned int __fastcall CCharacter__GetCheatInterval(void* This, void* NotUsed, int state);
	}
}