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

#include "RNXService.hpp"

#include <SimpleIniParser.hpp>
#include <string>
#include <iostream>
#include <iomanip>

#define DEFAULT_VERSION_MAJOR 2
#define DEFAULT_VERSION_MINOR 3

using namespace simpleIniParser;
using namespace std;

Result RNXService::GetReiNXVersion(Out<u32> maj, Out<u32> min) {
    // Get spoof version from INI file.
    auto config = Ini::parseFile("sdmc:/config/reinx-spoofer/config.ini");
    if (config == nullptr) {
        * maj.GetPointer() = DEFAULT_VERSION_MAJOR;
        * min.GetPointer() = DEFAULT_VERSION_MINOR;
        delete config;
        return 0;
    }

    auto version = config->findSection("version");
    if (version == nullptr) {
        * maj.GetPointer() = DEFAULT_VERSION_MAJOR;
        * min.GetPointer() = DEFAULT_VERSION_MINOR;
        delete config;
        return 0;
    }

    auto major = version->findFirstOption("major");
    auto minor = version->findFirstOption("minor");
    if (major == nullptr || minor == nullptr) {
        * maj.GetPointer() = DEFAULT_VERSION_MAJOR;
        * min.GetPointer() = DEFAULT_VERSION_MINOR;
        delete config;
        return 0;
    }

    * maj.GetPointer() = stoi(major->value);
    * min.GetPointer() = stoi(minor->value);
    delete config;
    return 0;
}

Result RNXService::SetHbTidForDelta(u64 tid) {
    // Set TID in Atmosphere ini file.
    auto loader = Ini::parseFile("sdmc:/atmosphere/loader.ini");
    if (loader == nullptr) {
        return 0;
    }

    auto hbl = loader->findSection("hbl_config");
    if (hbl == nullptr) {
        return 0;
    }

    auto title_id = hbl->findFirstOption("title_id");
    if (title_id == nullptr) {
        return 0;
    }

    stringstream stream;
    stream << setfill('0') << setw(sizeof(u64) * 2) << uppercase << hex << tid;
    title_id->value = stream.str();

    loader->writeToFile("sdmc:/atmosphere/loader.ini");
    delete loader;
    return 0;
}
