/**
  ******************************************************************************
  * @author		Anton Houzich
  * @version	V2.0.0
  * @date		29-April-2023
  * @mail		houzich_anton@mail.ru
  * discussion  https://t.me/BRUTE_FORCE_CRYPTO_WALLET
  ******************************************************************************
  */
#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <omp.h>
#include <iostream>

#include "base58.h"
#include "tools.h"
#include "utils.h"
#include "segwit_addr.h"

namespace tools {
	static LARGE_INTEGER performanceCountStart;
	static LARGE_INTEGER performanceCountStop;

	void start_time(void) {
		QueryPerformanceCounter(&performanceCountStart);
	}

	void stop_time(void) {
		QueryPerformanceCounter(&performanceCountStop);
	}

	void stop_time_and_calc(float* delay) {
		stop_time();
		LARGE_INTEGER perfFrequency;
		QueryPerformanceFrequency(&perfFrequency);
		*delay = (1000.0f * (float)(performanceCountStop.QuadPart - performanceCountStart.QuadPart) / (float)perfFrequency.QuadPart);
	}

	std::string formatWithCommas(double val)
	{
		uint64_t value = (uint64_t)val;
		std::stringstream ss;
		ss.imbue(std::locale("en_US.UTF-8"));
		ss << std::fixed << value;
		return ss.str();
	}

	std::string formatWithCommas(uint64_t value)
	{
		std::stringstream ss;
		ss.imbue(std::locale("en_US.UTF-8"));
		ss << std::fixed << value;
		return ss.str();
	}

	std::vector<uint8_t> hexStringToVector(const std::string& source)
	{
		if (std::string::npos != source.find_first_not_of("0123456789ABCDEFabcdef"))
		{
			// you can throw exception here
			return {};
		}

		union
		{
			uint64_t binary;
			char byte[8];
		} value{};

		auto size = source.size(), offset = (size % 16);
		std::vector<uint8_t> binary{};
		binary.reserve((size + 1) / 2);

		if (offset)
		{
			value.binary = std::stoull(source.substr(0, offset), nullptr, 16);

			for (auto index = (offset + 1) / 2; index--; )
			{
				binary.emplace_back(value.byte[index]);
			}
		}

		for (; offset < size; offset += 16)
		{
			value.binary = std::stoull(source.substr(offset, 16), nullptr, 16);
			for (auto index = 8; index--; )
			{
				binary.emplace_back(value.byte[index]);
			}
		}

		return binary;
	}


	int hexStringToBytes(const std::string& source, uint8_t* bytes, int max_len)
	{
		int len = 0;
		if (std::string::npos != source.find_first_not_of("0123456789ABCDEFabcdef"))
		{
			// you can throw exception here
			return 1;
		}

		union
		{
			uint64_t binary;
			char byte[8];
		} value{};

		auto size = source.size(), offset = (size % 16);

		if (offset)
		{
			value.binary = std::stoull(source.substr(0, offset), nullptr, 16);

			for (auto index = (offset + 1) / 2; index--; )
			{
				if (++len > max_len) return 1;
				*(bytes++) = value.byte[index];
			}
		}

		for (; offset < size; offset += 16)
		{
			value.binary = std::stoull(source.substr(offset, 16), nullptr, 16);
			for (auto index = 8; index--; )
			{
				if (++len > max_len) return 1;
				*(bytes++) = value.byte[index];
			}
		}

		return 0;
	}

	std::string uint32ToHexString(uint32_t data)
	{
		std::stringstream ss;
		ss << std::hex << std::uppercase;
		ss << std::setw(8) << std::setfill('0') << data;
		const std::string hexstr = ss.str();

		return hexstr;
	}
	std::string hash160Uint32ToHexString(std::array<uint32_t, 5>& hash160)
	{
		std::string hexstr = "";
		for (int i = 0; i < 5; i++) {
			hexstr.append(uint32ToHexString(hash160[i]));
		}
		return hexstr;
	}

	int hexStringHash160ToArrayUint32(const std::string& source, std::array<uint32_t, 5>& hash160)
	{
		if (std::string::npos != source.find_first_not_of("0123456789ABCDEFabcdef"))
		{
			return -1;
		}
		if (source.size() != 40)
		{
			return -1;
		}

		hash160[0] = std::stoul(source.substr(0, 8), nullptr, 16);
		hash160[1] = std::stoul(source.substr(8, 8), nullptr, 16);
		hash160[2] = std::stoul(source.substr(16, 8), nullptr, 16);
		hash160[3] = std::stoul(source.substr(24, 8), nullptr, 16);
		hash160[4] = std::stoul(source.substr(32, 8), nullptr, 16);

		return 0;
	}

	std::string vectorToHexString(std::vector<uint8_t>& data)
	{
		std::stringstream ss;
		ss << std::hex << std::uppercase;
		for (int i = 0; i < data.size(); i++)
			ss << std::setw(2) << std::setfill('0') << (uint16_t)((uint16_t)data[i] & 0xff);
		const std::string hexstr = ss.str();

		return hexstr;
	}

	std::string byteToHexString(uint8_t data)
	{
		std::stringstream ss;
		ss << std::hex << std::uppercase;
		ss << std::setw(2) << std::setfill('0') << (uint16_t)((uint16_t)data & 0xff);
		const std::string hexstr = ss.str();

		return hexstr;
	}

	std::string bytesToHexString(const uint8_t* data, int len)
	{
		std::string hexstr = "";
		for (int i = 0; i < len; i++) {
			hexstr.append(byteToHexString(data[i]));
		}
		return hexstr;
	}


	int encodeAddressBase58(const std::string& hash160hex, std::string& addr)
	{
		std::vector<unsigned char> datastr = hexStringToVector(hash160hex);
		if (datastr.size() != 20) {
			std::cerr << "ERROR SIZE HEX STRING: \"" << hash160hex << "\", LEGHT: " << datastr.size() << " BYTES" << std::endl;
			return -1;
		}
		std::vector<unsigned char> hash160 = { 0 };
		hash160.insert(hash160.end(), datastr.begin(), datastr.end());

		addr = EncodeBase58Check(hash160);

		return 0;
	}

	int encodeAddressBase58(const uint8_t* hash160, std::string& addr)
	{
		std::vector<uint8_t> datastr(hash160, hash160 + 20);
		std::vector<unsigned char> v_hash160 = { 0 };
		v_hash160.insert(v_hash160.end(), datastr.begin(), datastr.end());

		addr = EncodeBase58Check(v_hash160);

		return 0;
	}

	int decodeAddressBase58(const std::string& addr, std::string& hash160hex)
	{
		std::vector<unsigned char> hash160;
		if (DecodeBase58Check(addr, hash160, addr.size())) {
			if (hash160.size() != 21) {
				std::cerr << "ERROR HASH160. ADDRESS: \"" << addr << "\", HASH160 SIZE: " << hash160.size() << std::endl;
				return -1;
			}
			hash160hex = vectorToHexString(hash160);
			if (hash160hex.length() != 42) {
				std::cerr << "ERROR HASH160HEX: \"" << hash160hex << "\", HASH160HEX LENGHT: " << hash160hex.length() << std::endl;
				return -1;
			}
			hash160hex.erase(hash160hex.begin(), hash160hex.begin() + 2);

		}
		else
		{
			std::cerr << "ERROR decodeAddressBase58. LEGACY ADDRESS: \"" << addr << "\", LEGHT: " << addr.size() << std::endl;
			return -1;
		}

		return 0;
	}

	int decodeAddressBase58(const std::string& addr, uint8_t* hash160)
	{
		std::vector<unsigned char> v_hash160;

		if (DecodeBase58Check(addr, v_hash160, addr.size())) {
			if (v_hash160.size() != 21) {
				std::cerr << "ERROR HASH160. ADDRESS: \"" << addr << "\", HASH160 SIZE: " << v_hash160.size() << std::endl;
				return -1;
			}
			for (int i = 1; i < 20 + 1; i++) {
				*(hash160++) = v_hash160[i];
			}

		}
		else
		{
			std::cerr << "ERROR decodeAddressBase58. LEGACY ADDRESS: \"" << addr << "\", ADDRESS LEGHT: " << addr.size() << std::endl;
			return -1;
		}

		return 0;
	}



	int encodeAddressBase32(const std::string& hash160hex, std::string& addr)
	{
		std::vector<unsigned char> datastr = hexStringToVector(hash160hex);
		if (datastr.size() != 20) {
			std::cerr << "ERROR SIZE HEX STRING: \"" << hash160hex << "\", LEGHT: " << datastr.size() << " BYTES" << std::endl;
			return -1;
		}

		char address[42 + 1];
		uint8_t hash[20] = {0};

		for (int i = 0; i < 20; i++) hash[i] = datastr[i];

		native_segwit_addr_encode(address, "bc", 0, (const uint8_t*)hash, 20);
		addr = std::string(address);

		return 0;
	}

	int encodeAddressBase32(const uint8_t* hash160, std::string& addr)
	{
		char address[42 + 1];
		native_segwit_addr_encode(address, "bc", 0, (const uint8_t*)hash160, 20);
		addr = std::string(address);
		return 0;
	}


	int decodeAddressBase32(const std::string& addr, std::string& hash160hex)
	{
		int witver = 0;
		uint8_t hash160[20];
		size_t hash160_len = sizeof(hash160);

		if (native_segwit_addr_decode(&witver, hash160, &hash160_len, "bc", addr.c_str()) == 1) {

			hash160hex = bytesToHexString(hash160, 20);
		}
		else
		{
			std::cerr << "ERROR decodeAddressBase32(). SEGWIT ADDRESS: \"" << addr << "\", ADDRESS LEGHT: " << addr.size() << std::endl;
			return -1;
		}

		return 0;
	}

	int decodeAddressBase32(const std::string& addr, uint8_t* bytes)
	{
		int witver = 0;
		uint8_t hash160[20];
		size_t hash160_len = sizeof(hash160);

		if (native_segwit_addr_decode(&witver, hash160, &hash160_len, "bc", addr.c_str()) == 1) {

			for (int i = 0; i < 20; i++) {
				*(bytes++) = hash160[i];
			}

		}
		else
		{
			std::cerr << "ERROR decodeAddressBase32(). SEGWIT ADDRESS: \"" << addr << "\", ADDRESS LEGHT: " << addr.size() << std::endl;
			return -1;
		}

		return 0;
	}

	int encodeAddressBIP49(const uint8_t* hash160, std::string& addr)
	{
		std::vector<unsigned char> v_hash160temp = { 0x05 };
		v_hash160temp.insert(v_hash160temp.end(), hash160, hash160 + 20);
		addr = EncodeBase58Check(v_hash160temp);
		return 0;
	}

	int decodeAddressBIP49(const std::string& addr, std::string& hash160hex)
	{
		std::vector<unsigned char> hash160;
		if (DecodeBase58Check(addr, hash160, addr.size())) {
			if (hash160.size() != 21) {
				std::cerr << "ERROR HASH160. ADDRESS: \"" << addr << "\", HASH160 SIZE: " << hash160.size() << std::endl;
				return -1;
			}
			hash160hex = vectorToHexString(hash160);
			if (hash160hex.length() != 42) {
				std::cerr << "ERROR HASH160HEX: \"" << hash160hex << "\", HASH160HEX LENGHT: " << hash160hex.length() << std::endl;
				return -1;
			}
			hash160hex.erase(hash160hex.begin(), hash160hex.begin() + 2);

		}
		else
		{
			std::cerr << "ERROR decodeAddressBase58. BIP49 ADDRESS: \"" << addr << "\", LEGHT: " << addr.size() << std::endl;
			return -1;
		}

		return 0;
	}
	int decodeAddressBIP49(const std::string& addr, uint8_t* hash160)
	{
		std::vector<unsigned char> h160;
		if (DecodeBase58Check(addr, h160, addr.size())) {
			if (h160.size() != 21) {
				std::cerr << "ERROR HASH160. ADDRESS: \"" << addr << "\", HASH160 SIZE: " << h160.size() << std::endl;
				return -1;
			}
			for (int i = 1; i < (20 + 1); i++) {
				*(hash160++) = h160[i];
			}
		}
		else
		{
			std::cerr << "ERROR DecodeBase58Check. BIP49 ADDRESS: \"" << addr << "\", LEGHT: " << addr.size() << std::endl;
			return -1;
		}

		return 0;
	}



	void reverseHashUint32(uint32_t* hash_in, uint32_t* hash_out) {
		uint32_t hash160_reverse[5] = { 0 };
		REVERSE32_FOR_HASH(hash_in[0], hash160_reverse[0]);
		REVERSE32_FOR_HASH(hash_in[1], hash160_reverse[1]);
		REVERSE32_FOR_HASH(hash_in[2], hash160_reverse[2]);
		REVERSE32_FOR_HASH(hash_in[3], hash160_reverse[3]);
		REVERSE32_FOR_HASH(hash_in[4], hash160_reverse[4]);
		hash_out[0] = hash160_reverse[0];
		hash_out[1] = hash160_reverse[1];
		hash_out[2] = hash160_reverse[2];
		hash_out[3] = hash160_reverse[3];
		hash_out[4] = hash160_reverse[4];
	}
	void reverseHashArrayUint32(std::array<uint32_t, 5>& hash_in, std::array<uint32_t, 5>& hash_out) {
		uint32_t hash160_reverse[5] = { 0 };
		REVERSE32_FOR_HASH(hash_in[0], hash160_reverse[0]);
		REVERSE32_FOR_HASH(hash_in[1], hash160_reverse[1]);
		REVERSE32_FOR_HASH(hash_in[2], hash160_reverse[2]);
		REVERSE32_FOR_HASH(hash_in[3], hash160_reverse[3]);
		REVERSE32_FOR_HASH(hash_in[4], hash160_reverse[4]);
		hash_out[0] = hash160_reverse[0];
		hash_out[1] = hash160_reverse[1];
		hash_out[2] = hash160_reverse[2];
		hash_out[3] = hash160_reverse[3];
		hash_out[4] = hash160_reverse[4];
	}
}
