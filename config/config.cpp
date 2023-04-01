/**
  ******************************************************************************
  * @author		Anton Houzich
  * @version	V1.1.0
  * @date		1-April-2023
  * @mail		houzich_anton@mail.ru
  * discussion  https://t.me/BRUTE_FORCE_CRYPTO_WALLET
  ******************************************************************************
  */
#include "config.hpp"
#include <tao/config.hpp>

int parse_gonfig(ConfigClass* config, std::string path)
{
	try {
		const tao::config::value v = tao::config::from_file(path);

		config->folder_with_files_for_decode = access(v, tao::config::key("folder_with_files_for_decode")).get_string();
		config->folder_for_database_legacy = access(v, tao::config::key("folder_for_database_legacy")).get_string();
		config->folder_for_database_segwit = access(v, tao::config::key("folder_for_database_segwit")).get_string();
		config->folder_for_database_ethereum = access(v, tao::config::key("folder_for_database_ethereum")).get_string();	
	}
	catch (std::runtime_error& e) {
		std::cerr << "Error parse config.cfg file " << path << " : " << e.what() << '\n';
		throw;
	}
	catch (...) {
		std::cerr << "Error parse config.cfg file, unknown exception occured" << std::endl;
		throw;
	}
	return 0;
}


