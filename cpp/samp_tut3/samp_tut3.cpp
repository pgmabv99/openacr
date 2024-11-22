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
// Target: samp_tut3 (exe)
// Exceptions: yes
// Source: cpp/samp_tut3/samp_tut3.cpp
//

#include "include/algo.h"
#include "include/samp_tut3.h"

void samp_tut3::zd_value_Step() {
    Value &value_obj = *zd_value_First();
    prlog(algo::CurrUnTime() << " "<< value_obj.value);
    value_Delete(value_obj);
    // ind_beg(samp_tut3::_db_zd_value_curs,value_obj,samp_tut3::_db ){
    //     prlog(algo::CurrUnTime() << " "<< value_obj.value);
    // }
    // ind_end;
}

// void samp_tut3::update_Step()
// {
//     ind_beg(samp_tut3::_db_zd_value_curs, value_obj, samp_tut3::_db)
//     {
//         prlog(algo::CurrUnTime() << " " << value_obj.value);
//     }
//     ind_end;
// }
// void samp_tut3::update_Step() {
//     prlog("update_step enter"<<algo::CurrUnTime());
//     int num=algo::get_cycles() % 10;
//     cstring tmpstr;
//     if (Value *value=ind_value_Find(tmpstr<<"value_"<<num)) {
//         prlog("deleted "<<value->value);
//         value_Delete(*value);
//     }
//     if (ind_value_N()==0) {
//         _db.update=false;
//     }
// }

void samp_tut3::Main() {
    for (int i=0; i < 10; i++) {
        cstring tmpstr;
        Value &value_obj=value_Alloc();
        // value_obj.value=i;
        value_obj.value=tmpstr << "value_" << i;
        value_XrefMaybe(value_obj);
    }
    samp_tut3::MainLoop();
}
