/**
  ******************************************************************************
  * @author		Anton Houzich
  * @version	V1.1.0
  * @date		1-April-2023
  * @mail		houzich_anton@mail.ru
  * discussion  https://t.me/BRUTE_FORCE_CRYPTO_WALLET
  ******************************************************************************
  */
#pragma once
#include <string>

struct ConfigClass
{
public:
	std::string folder_with_files_for_decode = "";
	std::string folder_for_database_legacy = "";
	std::string folder_for_database_segwit = "";
	std::string folder_for_database_ethereum = "";
public:
	ConfigClass()
	{
	}
	~ConfigClass()
	{
	}
};


int parse_gonfig(ConfigClass* config, std::string path);

