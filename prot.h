#include <sstream>
#include <string>
#include <algorithm>
#include <list>
#include <string>
#include <windows.h>

#pragma once

void byebye()
{
	exit(0);
}

void ByeByePEHeaderFromMemory()
{
	DWORD OldProtect = 0;
	char* pBaseAddr = (char*)GetModuleHandle(NULL);
	VirtualProtect(pBaseAddr, 4096,
		PAGE_READWRITE, &OldProtect);
	SecureZeroMemory(pBaseAddr, 4096);
}

void dbgf()
{
	if (IsDebuggerPresent())
	{
		byebye();
	}
}

void adbg()
{
	if (FindWindowA(NULL, ("The Wireshark Network Analyzer"))) { byebye(); }
	if (FindWindowA(NULL, ("Progress Telerik Fiddler Web Debugger"))) { byebye(); }
	if (FindWindowA(NULL, ("Fiddler"))) { byebye(); }
	if (FindWindowA(NULL, ("HTTP Debugger"))) { byebye(); }
	if (FindWindowA(NULL, ("x64dbg"))) { byebye(); }
	if (FindWindowA(NULL, ("dnSpy"))) { byebye(); }
	if (FindWindowA(NULL, ("FolderChangesView"))) { byebye(); }
	if (FindWindowA(NULL, ("BinaryNinja"))) { byebye(); }
	if (FindWindowA(NULL, ("HxD"))) { byebye(); }
	if (FindWindowA(NULL, ("Cheat Engine 7.4"))) { byebye(); }
	if (FindWindowA(NULL, ("Cheat Engine 7.3"))) { byebye(); }
	if (FindWindowA(NULL, ("Cheat Engine 7.2"))) { byebye(); }
	if (FindWindowA(NULL, ("Cheat Engine 7.1"))) { byebye(); }
	if (FindWindowA(NULL, ("Cheat Engine 7.0"))) { byebye(); }
	if (FindWindowA(NULL, ("Cheat Engine 6.9"))) { byebye(); }
	if (FindWindowA(NULL, ("Cheat Engine 6.8"))) { byebye(); }
	if (FindWindowA(NULL, ("Ida"))) { byebye(); }
	if (FindWindowA(NULL, ("Ida Pro"))) { byebye(); }
	if (FindWindowA(NULL, ("Ida Freeware"))) { byebye(); }
	if (FindWindowA(NULL, ("HTTP Debugger Pro"))) { byebye(); }
	if (FindWindowA(NULL, ("Process Hacker"))) { byebye(); }
	if (FindWindowA(NULL, ("Process Hacker 2"))) { byebye(); }
	if (FindWindowA(NULL, ("OllyDbg"))) { byebye(); }
}

static void WipeNetCache()
{
	system("@RD /S /Q \"C:\\Users\\%username%\\AppData\\Local\\Microsoft\\Windows\\INetCache\\IE\" >nul 2>&1");
}

void prot()
{
	adbg();
	dbgf();
	ByeByePEHeaderFromMemory();
	WipeNetCache();
}
