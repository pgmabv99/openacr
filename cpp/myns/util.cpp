//
// License: GPL
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
// Target: myns (exe) -- create program and inherit from db
// Exceptions: yes
// Source: cpp/myns/util.cpp
//

#include "cpp/myns/util.h"

// steps callbacks
void myns::sched1_Step()
{
    if (step_display_flag)
    {

        step_invocation_count++;
        prlog("Enter  " << __func__ << " at " << algo::CurrUnTime() << "step invocation count " << step_invocation_count);
        scan_zd_db_order_via_sched1_fstep();
    }
}

void myns::zd_order_Step() {
    if (step_display_flag)
    {
        prlog("Enter  " << __func__ << " at " << algo::CurrUnTime() );
        scan_zd_db_order_via_own_fstep();
    }
}
