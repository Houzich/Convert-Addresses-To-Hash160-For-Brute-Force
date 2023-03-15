#pragma once
#include <string>



struct ConfigClass
{
public:
	std::string folder_with_files_for_decode = "";
	std::string folder_for_database_legacy = "";
	std::string folder_for_database_segwit = "";
public:
	ConfigClass()
	{
	}
	~ConfigClass()
	{
	}
};


int parse_gonfig(ConfigClass* config, std::string path);

