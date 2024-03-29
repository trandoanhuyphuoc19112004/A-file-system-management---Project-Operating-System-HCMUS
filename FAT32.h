#pragma once
#include "Utils.h"
#include <Windows.h>
#include <vector>



class FAT32
{
private:
	LPCWSTR _drive_name; 

	int _bytes_per_sector;
	int _sectors_per_cluster;
	int _sectors_in_bootsector;
	int _fat_num; 
	int _entry_num;
	int _volume_size;
	int _fat_table_size;
	int _first_sector_of_data;

	BYTE* BootSector; 
	BYTE* rdet;
	BYTE* fat_table; 

	std::vector<ItemProperties>  list;
	std::vector<ItemProperties> innerlist; 

public:
	~FAT32(); 
	FAT32(LPCWSTR drivename);
public:
	void getDiskInformation(); 
public:
	 BYTE* getBootSector()
	{
		return BootSector;
	}
public:
	vector<ItemProperties> getList()
	{
		return list; 
	}
public:
	void read();
	void readSDET(const ItemProperties& dir, std::vector<ItemProperties> InnerList);
	void readDIR(std::vector<ItemProperties>& list, int offsetDIR, int sector_index, int pointer);
	void readFAT(std::vector<ItemProperties>& list, int offset_FatTable, int pointer_of_fattable, int sector_index_of_fat_table);
	void printFolder(std::vector<ItemProperties>& List);
	void readTXT(const ItemProperties& file);
	void printChosen(std::vector<ItemProperties> List);
};




