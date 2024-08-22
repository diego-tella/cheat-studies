#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


int main(int argc, char *argv[]) {
	DWORD pid  = NULL; //define pid as null
	int valueAmmo = 1000; //the new value of the ammo
    HWND idWindow = FindWindowA(0,  ("AssaultCube")); //actual windows identifier to the AssultCube. It is a identifier to the window of assaultcube.
	GetWindowThreadProcessId(idWindow, &pid); //pass to pid the PID of the AssaultCube
	
	HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid); //pass to process an id to the process. PROCESS_ALL_ACCESS means all possible rights
	
	WriteProcessMemory(process, 0x0074E640, &valueAmmo, sizeof(valueAmmo), 0); //it will write to the 0x0074E640 (the ammo address of the game) the new value. 
	return 0;
}
