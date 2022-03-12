#include <iostream>
#include <Windows.h>

#include "xorstr.h"
#include "prot.h"

#include "dll.h"
#include "injector.h"

#include "utilsmapper.h"
#include "utilsmapper.hpp"

auto dll_path = xorstr("C:\\Windows\\System32\\injector.exe");
auto injector_path = xorstr("C:\\Windows\\System32\\dll.dll");

char title[100];

HWND ratio = NULL;

void randomstring(char* sStr, unsigned int iLen)
{
	char Syms[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	unsigned int Ind = 0;
	srand(time(NULL) + rand());
	while (Ind < iLen)
	{
		sStr[Ind++] = Syms[rand() % 62];
	}
	sStr[iLen] = '\0';
}

std::string randomexestring(const size_t length)
{
	std::string r;
	static const char bet[] = { "abcdefghijklmnopqrstuvwxyzz" };
	srand((unsigned)time(NULL) * 5);
	for (int i = 0; i < length; ++i)
		r += bet[rand() % (sizeof(bet) - 1)];
	return r;
}

std::string path()
{
	char shitter[_MAX_PATH];
	GetModuleFileNameA(NULL, shitter, _MAX_PATH);
	return std::string(shitter);
}

void createfiles()
{
    utils::CreateFileFromMemory(dll_path, reinterpret_cast<const char*>(dll), sizeof(dll));
    utils::CreateFileFromMemory(injector_path, reinterpret_cast<const char*>(injector), sizeof(injector));
}

DWORD fart(LPVOID in)
{
	while (1)
	{
		prot();

		randomstring(title, 16);
		SetConsoleTitleA(title);

	}
}

void nigger()
{
	system(xorstr("taskkill /f /im FortniteClient-Win64-Shipping_EAC.exe >nul 2>&1"));
	system(xorstr("taskkill /f /im FortniteClient-Win64-Shipping_BE.exe >nul 2>&1"));
	system(xorstr("taskkill /f /im FortniteClient-Win64-Shipping.exe >nul 2>&1"));
	system(xorstr("taskkill /f /im EpicGamesLauncher.exe >nul 2>&1"));
	system(xorstr("taskkill /f /im FortniteLauncher.exe >nul 2>&1"));
	system(xorstr("sc stop BEService >nul 2>&1"));
	system(xorstr("sc stop BEDaisy >nul 2>&1"));
	system(xorstr("sc stop EasyAntiCheat >nul 2>&1"));
	system(xorstr("sc stop EasyAntiCheatSys >nul 2>&1"));
	system(xorstr("net stop FACEIT >nul 2>&1"));
	system(xorstr("net stop ESEADriver2 >nul 2>&1"));
	system(xorstr("sc stop HTTPDebuggerPro >nul 2>&1"));
	system(xorstr("sc stop KProcessHacker3 >nul 2>&1"));
	system(xorstr("sc stop KProcessHacker2 >nul 2>&1"));
	system(xorstr("sc stop KProcessHacker1 >nul 2>&1"));
	system(xorstr("sc stop wireshark >nul 2>&1"));
	system(xorstr("sc stop npf >nul 2>&1"));
}

int main()
{
	CreateThread(NULL, NULL, reinterpret_cast<LPTHREAD_START_ROUTINE>(fart), NULL, NULL, NULL);

	std::string name = randomexestring(8) + ".exe";
	std::rename(path().c_str(), name.c_str());

	nigger();

	std::cout << xorstr("\n welcome to crucial github loader");

	Sleep(2000);

	system(xorstr("cls"));

	printf_s(xorstr("\n waiting for fortnite\n"));

	while (ratio == NULL)
	{
		ratio = FindWindowA(NULL, xorstr("Fortnite  "));
	}

    std::cout << xorstr("\n fortnite found, injecting...");

    Sleep(30000);

	createfiles();

    system(xorstr("C:\\Windows\\System32\\injector.exe C:\\Windows\\System32\\dll.dll"));

	Sleep(2000);

	remove(xorstr("C:\\Windows\\System32\\injector.exe"));

	remove(xorstr("C:\\Windows\\System32\\dll.dll"));

}