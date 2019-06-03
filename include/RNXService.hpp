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

#include <switch.h>
#include <stratosphere.hpp>

enum RNXServiceCmd {
    RNX_CMD_GetReiNXVersion = 0,
    RNX_CMD_SetHbTidForDelta = 1,
};

class RNXService final : public IServiceObject {        
    private:
        Result GetReiNXVersion(Out<u32> maj, Out<u32> min);
        Result SetHbTidForDelta(u64 tid);

    public:
        DEFINE_SERVICE_DISPATCH_TABLE {
            MakeServiceCommandMeta<RNX_CMD_GetReiNXVersion, &RNXService::GetReiNXVersion>(),
            MakeServiceCommandMeta<RNX_CMD_SetHbTidForDelta, &RNXService::SetHbTidForDelta>(),
        };
};
