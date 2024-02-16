#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include "Utils.h"
#include "FAT32.h"

int main(int argc, char** argv)
{
	std::wstring drivename; 
	std::cout << "AN FILE SYSTEM MANAGEMENT" << std::endl; 
	std::cout << "Enter your removable disks:"; 

	std::getline(std::wcin, drivename); 
	std::wstring path = L"\\\\.\\\\" + drivename + L":";

	FAT32 drive(path.c_str()); 
	printHexTable(drive.getBootSector()); 
	std:: cout << "============================" << std::endl;
	drive.getDiskInformation();
}