/**
  ******************************************************************************
  * @author		Anton Houzich
  * @version	V2.0.0
  * @date		29-April-2023
  * @mail		houzich_anton@mail.ru
  * discussion  https://t.me/BRUTE_FORCE_CRYPTO_WALLET
  ******************************************************************************
  */
#include "main.h"
#include <sstream>
#include <iomanip>
#include <iostream>
#include <omp.h>
#include <set>
#include <random>
#include <fstream>
#include <filesystem>

#include "stdafx.h"
#include "tools.h"
#include "utils.h"
#include "base58.h"
#include "segwit_addr.h"
#include "Config.hpp"

namespace tools {

	int open_or_create_files_for_write(std::string folger_for_result, std::ofstream of[256]) {
		int ret = 0;
		std::string num_tables;
		for (int i = 0; i < 256; i++) {
			std::string file_path = folger_for_result + byteToHexString(i) + ".csv";
			of[i].open(file_path, std::ios::app);
			if (of[i].is_open())
			{
			}
			else
			{
				std::cerr << "\n!!!ERROR CREATE FILE " << file_path << "!!!\n" << std::endl;
				ret = -1;
				break;
			}
		}

		return ret;
	}

	int close_files(std::ofstream of[256]) {

		for (int i = 0; i < 256; i++) {
			of[i].close();
		}
		return 0;
	}



	int decode_addr_and_push_to_files(std::ofstream of[256], std::vector<std::string>& lines, size_t* count_line, size_t* count_fail_line, int type_address) {
		int ret = 0;
		size_t cnt_fail_line = 0;
		size_t cnt_line = 0;
#pragma omp parallel for reduction(+:cnt_fail_line, cnt_line)
		for (int x = 0; x < lines.size(); x++) {

			if ((x % 100000) == 0) {
#pragma omp critical
				{
					std::cout << "\rCHECK AND SAVE " << x << " LINES";
				}
			}

			std::string addr_str = lines[x];
			std::string hash160hex;


			if (
				((type_address == ADDRESS_BITCOIN_LEGACY) && ((addr_str.size() == 33) || (addr_str.size() == 34)) && (addr_str[0] == '1')) ||
				((type_address == ADDRESS_BITCOIN_NATIVE_SEGWIT) && (addr_str.size() == 42) && (addr_str[0] == 'b') && (addr_str[3] == 'q')) ||
				((type_address == ADDRESS_BITCOIN_SEGWIT) && (addr_str.size() == 34) && (addr_str[0] == '3')) ||
				((type_address == ADDRESS_ETHEREUM) && (addr_str.size() == 42) && (addr_str[0] == '0') && ((addr_str[1] == 'x')||(addr_str[1] == 'X'))) ||
				((type_address == ADDRESS_ETHEREUM) && (addr_str.size() == 40))
				)
			{

				if (type_address == ADDRESS_BITCOIN_LEGACY)
				{
					ret = decodeAddressBase58(addr_str, hash160hex);
				}		
				else if (type_address == ADDRESS_BITCOIN_SEGWIT)
				{
					ret = decodeAddressBIP49(addr_str, hash160hex);
				}
				else if (type_address == ADDRESS_BITCOIN_NATIVE_SEGWIT)
				{
					ret = decodeAddressBase32(addr_str, hash160hex);
				}
				else if (type_address == ADDRESS_ETHEREUM)
				{
					if (addr_str.size() == 42) hash160hex = addr_str.substr(2, 42);
					else hash160hex = addr_str;
				}


				if (ret) {
#pragma omp critical
					{
						std::cerr << "\rERROR DECODE ADDRESS!!! Address = " << addr_str << ", lenght = " << addr_str.size() << std::endl;
					}
					ret = -1;
					break;
				}


				std::string name_table = hash160hex.substr(0, 2);
				uint8_t num_table = std::stoi(name_table, nullptr, 16);
				if (of[num_table].is_open())
				{
#pragma omp critical (SAVE_IN_FILE)
					{
						cnt_line += 1;
						of[num_table] << hash160hex << std::endl;
					}
				}
				else
				{
					std::cerr << "\n!!!ERROR CREATE FILE " << byteToHexString(num_table) << ".csv!!!\n" << std::endl;

					ret = -1;
					break;
				}

			}
			else
			{
				cnt_fail_line += 1;
			}

		}
		*count_fail_line = cnt_fail_line;
		*count_line = cnt_line;
		return ret;
	}


	int decode_file_and_save_result(std::string filepath, std::string folger_for_result, std::ofstream of[256], int type_address) {
		std::ifstream input_file;
		input_file.open(filepath, std::ifstream::in);
		if (!input_file.is_open())
		{
			std::cerr << "\n!!!ERROR OPEN FILE: " << filepath << std::endl;
			return -1;
		}
		int ret = open_or_create_files_for_write(folger_for_result, of);
		if (ret != 0) {
			input_file.close();
			close_files(of);
			return ret;
		}

		std::string line;
		size_t count_fail_lines = 0;
		size_t count_line = 0;

			size_t count = 0;
			size_t all_count = 0;
			std::vector<std::string> lines;
			while (getline(input_file, line)) {
				lines.push_back(line);
				count++;
				if ((count % 100000) == 0) {
					std::cout << "\rREAD " << count << " ROWS";
				}
			}
			all_count += lines.size();
			std::cout << "\rREAD " << all_count << " ROWS";

			std::cout << "\nWAIT DECODE AND SAVE...";

			ret = decode_addr_and_push_to_files(of, lines, &count_line, &count_fail_lines, type_address);
			if (ret != 0) {
				std::cerr << "\n!!!ERROR DECODE FILE: " << filepath << std::endl;
				input_file.close();
				close_files(of);
				return ret;
			}
		input_file.close();
		close_files(of);
		std::cout << "\rDECODE ADDRESSES: "<< count_line  <<" | FAILED LINES: " << count_fail_lines << std::endl;
		return 0;
	}

	int sort_all_files(std::string folger_for_result) {

		int ret = 0;
		size_t all_count_in_all_files = 0;
#pragma omp parallel for shared(all_count_in_all_files)
		for (int x = 0; x < 256; x++) {
			size_t count_addrs = 0;
			std::string file_path = folger_for_result + byteToHexString(x) + ".csv";
			std::ifstream inFile(file_path);
			std::ofstream outFile;
			int64_t cnt_lines = std::count(std::istreambuf_iterator<char>(inFile), std::istreambuf_iterator<char>(), '\n');
			inFile.close();
			if (cnt_lines != 0) {
				inFile.open(file_path, std::ifstream::in);
				if (inFile.is_open())
				{
					std::vector<std::array<uint32_t, 5>> hashes;
					std::string line;
					while (getline(inFile, line)) {
						std::array<uint32_t, 5> hash160{ 0,0,0,0,0 };
						if (hexStringHash160ToArrayUint32(line, hash160) == 0)
						{
							reverseHashArrayUint32(hash160, hash160);
							hashes.push_back(hash160);
						}
					}
					struct
					{
						bool operator()(std::array<uint32_t, 5> a, std::array<uint32_t, 5> b) const {
							if (a[0] < b[0]) return true;
							else if (a[0] > b[0]) return false;
							if (a[1] < b[1]) return true;
							else if (a[1] > b[1]) return false;
							if (a[2] < b[2]) return true;
							else if (a[2] > b[2]) return false;
							if (a[3] < b[3]) return true;
							else if (a[3] > b[3]) return false;
							if (a[4] < b[4]) return true;
							else if (a[4] > b[4]) return false;
							return false;
						}
					}customLess;
					std::sort(hashes.begin(), hashes.end(), customLess);
					auto last = std::unique(hashes.begin(), hashes.end());
					hashes.erase(last, hashes.end());

					inFile.close();
					outFile.open(file_path);
					if (outFile.is_open())
					{
						for (int ii = 0; ii < hashes.size(); ii++) {
							reverseHashArrayUint32(hashes[ii], hashes[ii]);
							outFile << hash160Uint32ToHexString(hashes[ii]) << std::endl;
						}
					}
					else
					{
						std::cerr << "\n!!!ERROR open file for write: " << file_path << std::endl;
						ret = -1;
						break;
					}

					outFile.close();
					count_addrs += hashes.size();

				}
				else
				{
					std::cerr << "\n!!!ERROR open file: " << file_path << std::endl;
					ret = -1;
					break;
				}
#pragma omp critical 
				{
					std::cout << "SORT " << count_addrs << " ROWS IN FILE " << file_path << std::endl;
					all_count_in_all_files += count_addrs;
				}
			}
			else {
			}

		}

		if (ret == -1) return ret;
		std::cout << "!!!SORT LINES: " << all_count_in_all_files << std::endl;
		return ret;
	}



	int DecodeFile(ConfigClass config) {
		static std::ofstream of[256];
		int ret = 0;
		std::string filename = "";
		std::cout << "file path: " << config.folder_with_files_for_decode << std::endl;

		std::cout << "Please, enter file name: ";
		//std::cin >> filename;
		//std::cin.clear();
		std::getline(std::cin, filename);
		int type_address = -1;
		while (type_address == -1)
		{
			std::cout << 
				"[" << ADDRESS_BITCOIN_LEGACY << "] - Bitcoin Legacy (1\"address\")(BIP32, BIP44),\n" <<
				"[" << ADDRESS_BITCOIN_SEGWIT << "] - Bitcoin SegWit (3\"address\")(BIP49),\n" <<
				"[" << ADDRESS_BITCOIN_NATIVE_SEGWIT << "] - Bitcoin Native SegWit (bc1q\"address\")(BIP84),\n" <<
				"[" << ADDRESS_ETHEREUM << "] - Ethereum (0x\"address\" or \"address\")" << std::endl;
			std::cout << "Please, enter addresses type: ";
			std::cin >> type_address;
			if (type_address != ADDRESS_BITCOIN_LEGACY && type_address != ADDRESS_BITCOIN_NATIVE_SEGWIT && type_address != ADDRESS_BITCOIN_SEGWIT && type_address != ADDRESS_ETHEREUM)
			{
				type_address = -1;
				std::cout << "Invalid addresses type! Please type 0..3" << std::endl;
			}
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}


		std::string filepath = config.folder_with_files_for_decode + "\\" + filename;
		std::string folger_for_result;
		if (type_address == ADDRESS_BITCOIN_LEGACY) folger_for_result = config.folder_for_tables_legacy + "\\";
		else if (type_address == ADDRESS_BITCOIN_SEGWIT) folger_for_result = config.folder_for_tables_segwit + "\\";
		else if (type_address == ADDRESS_BITCOIN_NATIVE_SEGWIT) folger_for_result = config.folder_for_tables_native_segwit + "\\";
		else if (type_address == ADDRESS_ETHEREUM) folger_for_result = config.folder_for_tables_ethereum + "\\";
		std::cout << "--------------------------------------------" << std::endl;
		if (type_address == ADDRESS_BITCOIN_LEGACY) std::cout << "Decode Bitcoin legacy addresses (1\"address\")(BIP32, BIP44)" << std::endl;
		else if (type_address == ADDRESS_BITCOIN_SEGWIT) std::cout << "Decode Bitcoin segwit addresses (3\"address\")(BIP49)" << std::endl;
		else if(type_address == ADDRESS_BITCOIN_NATIVE_SEGWIT) std::cout << "Decode Bitcoin native segwit addresses (bc1q\"address\")(BIP84)" << std::endl;
		else if (type_address == ADDRESS_ETHEREUM) std::cout << "Decode Ethereum addresses (0x\"address\" or \"address\")" << std::endl;
		std::cout << "file: " << filepath << std::endl;
		std::cout << "folder for save result: " << folger_for_result << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "START DECODE" << std::endl;
		ret = decode_file_and_save_result(filepath, folger_for_result, of, type_address);
		if (ret != 0) {
			std::cout << "\n\nERROR DECODE!!!" << std::endl;
			return ret;
		}
		std::cout << "END DECODE" << std::endl;
		std::cout << "START SORT AND SAVE" << std::endl;
		ret = sort_all_files(folger_for_result);
		if (ret != 0) {
			std::cout << "\n\nERROR SORT!!!" << std::endl;
			return ret;
		}
		std::cout << "******************************************************************************************************" << std::endl;
		std::cout << "******************************************************************************************************" << std::endl;
		std::cout << "******************************************************************************************************" << std::endl;
		std::cout << "******************************************************************************************************" << std::endl;
		std::cout << "******************************************************************************************************" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "END OK!" << std::endl;
		std::cout << "" << std::endl;
		return ret;
	}

}
