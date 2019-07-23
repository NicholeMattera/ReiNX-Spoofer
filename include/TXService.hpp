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

#pragma once

#include <stratosphere.hpp>
#include <string>
#include <switch.h>

enum TXServiceCmd {
    TX_CMD_123 = 123,
    TX_CMD_124 = 124,
    TX_CMD_125 = 125,
    TX_CMD_126 = 126,
    TX_CMD_127 = 127,
    TX_CMD_128 = 128,
    TX_CMD_129 = 129,
    TX_CMD_130 = 130,
    TX_CMD_131 = 131,
    TX_CMD_132 = 132,
    TX_CMD_133 = 133,
    TX_CMD_134 = 134,
    TX_CMD_135 = 135,
    TX_CMD_136 = 136,
    TX_CMD_137 = 137
};

class TXService final : public IServiceObject {        
    private:
        Result TX_123(InPointer<char> data);
        Result TX_124(Out<u32> ret);
        Result TX_125();
        Result TX_126(Out<u32> ret);
        Result TX_127();
        Result TX_128();
        Result TX_129();
        Result TX_130();
        Result TX_131();
        Result TX_132();
        Result TX_133();
        Result TX_134();
        Result TX_135();
        Result TX_136();
        Result TX_137();

        Result GetValueFromConfig(std::string optionName);

    public:
        DEFINE_SERVICE_DISPATCH_TABLE {
            MakeServiceCommandMeta<TX_CMD_123, &TXService::TX_123, TXService>(),
            MakeServiceCommandMeta<TX_CMD_124, &TXService::TX_124, TXService>(),
            MakeServiceCommandMeta<TX_CMD_125, &TXService::TX_125, TXService>(),
            MakeServiceCommandMeta<TX_CMD_126, &TXService::TX_126, TXService>(),
            MakeServiceCommandMeta<TX_CMD_127, &TXService::TX_127, TXService>(),
            MakeServiceCommandMeta<TX_CMD_128, &TXService::TX_128, TXService>(),
            MakeServiceCommandMeta<TX_CMD_129, &TXService::TX_129, TXService>(),
            MakeServiceCommandMeta<TX_CMD_130, &TXService::TX_130, TXService>(),
            MakeServiceCommandMeta<TX_CMD_131, &TXService::TX_131, TXService>(),
            MakeServiceCommandMeta<TX_CMD_132, &TXService::TX_132, TXService>(),
            MakeServiceCommandMeta<TX_CMD_133, &TXService::TX_133, TXService>(),
            MakeServiceCommandMeta<TX_CMD_134, &TXService::TX_134, TXService>(),
            MakeServiceCommandMeta<TX_CMD_135, &TXService::TX_135, TXService>(),
            MakeServiceCommandMeta<TX_CMD_136, &TXService::TX_136, TXService>(),
            MakeServiceCommandMeta<TX_CMD_137, &TXService::TX_137, TXService>(),
        };
};
