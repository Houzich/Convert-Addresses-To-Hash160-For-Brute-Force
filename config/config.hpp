/**
  ******************************************************************************
  * @author		Anton Houzich
  * @version	V1.2.0
  * @date		16-April-2023
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
	std::string folder_for_tables_legacy = "";
	std::string folder_for_tables_native_segwit = "";
	std::string folder_for_tables_segwit = "";
	std::string folder_for_tables_ethereum = "";
public:
	ConfigClass()
	{
	}
	~ConfigClass()
	{
	}
};


int parse_gonfig(ConfigClass* config, std::string path);

