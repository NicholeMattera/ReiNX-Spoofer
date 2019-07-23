/*
 * ReiNX Spoofer
 * Copyright (c) 2019 Steven Mattera
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "TXService.hpp"

#include <SimpleIniParser.hpp>

// This is obviously not the correct value that should be returned by the TX service.
#define DEFAULT_VALUE 0x9001

using namespace simpleIniParser;
using namespace std;

Result TXService::TX_123(InPointer<char> data) {
    return GetValueFromConfig("tx123_result");
}

Result TXService::TX_124(Out<u32> ret) {
    ret.SetValue(GetValueFromConfig("tx124_value"));
    return GetValueFromConfig("tx124_result");
}

Result TXService::TX_125() {
    return GetValueFromConfig("tx125_result");
}

Result TXService::TX_126(Out<u32> ret) {
    ret.SetValue(GetValueFromConfig("tx126_value"));
    return GetValueFromConfig("tx126_result");
}

Result TXService::TX_127() {
    return GetValueFromConfig("tx127_result");
}

Result TXService::TX_128() {
    return GetValueFromConfig("tx128_result");
}

Result TXService::TX_129() {
    return GetValueFromConfig("tx129_result");
}

Result TXService::TX_130() {
    return GetValueFromConfig("tx130_result");
}

Result TXService::TX_131() {
    return GetValueFromConfig("tx131_result");
}

Result TXService::TX_132() {
    return GetValueFromConfig("tx132_result");
}

Result TXService::TX_133() {
    return GetValueFromConfig("tx133_result");
}

Result TXService::TX_134() {
    return GetValueFromConfig("tx134_result");
}

Result TXService::TX_135() {
    return GetValueFromConfig("tx135_result");
}

Result TXService::TX_136() {
    return GetValueFromConfig("tx136_result");
}

Result TXService::TX_137() {
    return GetValueFromConfig("tx137_result");
}

Result TXService::GetValueFromConfig(string optionName) {
    auto config = Ini::parseFile("sdmc:/config/reinx-spoofer/config.ini");
    if (config == nullptr) {
        return DEFAULT_VALUE;
    }

    auto tx = config->findSection("tx");
    if (tx == nullptr) {
        delete config;
        return DEFAULT_VALUE;
    }

    auto option = tx->findFirstOption(optionName);
    if (option == nullptr) {
        delete config;
        return DEFAULT_VALUE;
    }

    auto value = stoi(option->value, nullptr, 0);
    delete config;
    return value;
}
