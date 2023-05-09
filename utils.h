/**
  ******************************************************************************
  * @author		Anton Houzich
  * @version	V2.0.0
  * @date		29-April-2023
  * @mail		houzich_anton@mail.ru
  * discussion  https://t.me/BRUTE_FORCE_CRYPTO_WALLET
  ******************************************************************************
  */
#pragma once
#include <string>
#include <vector>
#include <array>
namespace tools {
	void start_time(void);
	void stop_time_and_calc(float* delay);
	std::string formatWithCommas(double val);
	std::string formatWithCommas(uint64_t value);
	std::vector<uint8_t> hexStringToVector(const std::string& source);
	std::string byteToHexString(uint8_t data);
	std::string bytesToHexString(const uint8_t* data, int len);
	int hexStringToBytes(const std::string& source, uint8_t* bytes, int max_len);
	std::string hash160Uint32ToHexString(std::array<uint32_t, 5>& hash160);
	int hexStringHash160ToArrayUint32(const std::string& source, std::array<uint32_t, 5>& hash160);
	std::string vectorToHexString(std::vector<uint8_t>& data);
	int encodeAddressBase58(const std::string& hash160hex, std::string& addr);
	int encodeAddressBase58(const uint8_t* hash160, std::string& addr);
	int decodeAddressBase58(const std::string& addr, std::string& hash160hex);
	int decodeAddressBase58(const std::string& addr, uint8_t* hash160);
	int encodeAddressBase32(const std::string& hash160hex, std::string& addr);
	int encodeAddressBase32(const uint8_t* hash160, std::string& addr);
	int decodeAddressBase32(const std::string& addr, std::string& hash160hex);
	int decodeAddressBase32(const std::string& addr, uint8_t* bytes);
	int encodeAddressBIP49(const uint8_t* hash160, std::string& addr);
	int decodeAddressBIP49(const std::string& addr, std::string& hash160hex);
	int decodeAddressBIP49(const std::string& addr, uint8_t* hash160);
	void reverseHashUint32(uint32_t* hash_in, uint32_t* hash_out);
	void reverseHashArrayUint32(std::array<uint32_t, 5>& hash_in, std::array<uint32_t, 5>& hash_out);
}