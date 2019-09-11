/*
 * ReiNX Spoofer
 * Copyright (c) 2019 Nichole Mattera
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

Result TXService::TX_123(InPointer<char> data) {
    return 0;
}

Result TXService::TX_124(Out<u32> ret) {
    ret.SetValue(0x100);
    return 0;
}

Result TXService::TX_125() {
    return 0;
}

Result TXService::TX_126(Out<u32> ret) {
    ret.SetValue(0x666);
    return 0;
}

Result TXService::TX_127() {
    return 0x666;
}

Result TXService::TX_128() {
    return 0;
}

Result TXService::TX_129() {
    return 1;
}

Result TXService::TX_130() {
    return 0;
}

Result TXService::TX_131() {
    return 1;
}

Result TXService::TX_132() {
    return 0;
}

Result TXService::TX_133() {
    return 0;
}

Result TXService::TX_134() {
    return 0;
}

Result TXService::TX_135() {
    return 1;
}

Result TXService::TX_136() {
    return 0;
}

Result TXService::TX_137() {
    return 0;
}
