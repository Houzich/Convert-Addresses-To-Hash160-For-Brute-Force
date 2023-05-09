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
#include <main.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <thread>

#include "tools.h"
#include "segwit_addr.h"
#include "config.hpp"


using namespace tools;

int main()
{





    ConfigClass config;
    try {
        parse_gonfig(&config, "config.cfg");
    }
    catch (...) {
        while (1) {
            std::this_thread::sleep_for(std::chrono::seconds(100));
        }

    }
    int ret = 0;
    while (ret == 0) {
        ret = DecodeFile(config);
    }

    std::this_thread::sleep_for(std::chrono::seconds(100));
    return 0;
}
