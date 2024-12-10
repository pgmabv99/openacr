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
// Target: sample (exe)
// Exceptions: yes
// Source: cpp/sample/sample.cpp
//
// fix1

#include "include/algo.h"
#include "include/algo.h"
#include "include/sample.h"

void sample::CreateRecord(int i) {
    sample::FRec &rec_obj = rec_Alloc();
    // heap key
    rec_obj.rec.key1=i;
    rec_obj.rec.key2=i;
    cstring key3 ;
    key3 << "rec_" << i;
    rec_obj.rec.key3=key3;
    // separate hash key
    rec_obj.hashkey = i+100;
    rec_XrefMaybe(rec_obj);
    if (!rec_XrefMaybe(rec_obj)) {
        prlog("did NOT cross reference "<<rec_obj.rec);
        rec_Delete(rec_obj);
    }else{
        prlog("added  and cross referenced "<<rec_obj.rec);
    }
}


int step_count = 0;
void sample::bh_rec_Step() {
    int r = random() % 100;
    step_count++;
    sample::FRec* rec_obj1 = bh_rec_First();
    prlog("found :step_count " <<step_count << " " << rec_obj1->rec << " bh_rec_count " << bh_rec_N());
    if (r > 50) {
        prlog("delay by 10: "<<rec_obj1->rec);
        rec_obj1->rec.key2 += 10;
        bh_rec_Reheap(*rec_obj1);
    } else if (r > 25 && bh_rec_N()>1) {
        prlog("process and delete: "<<bh_rec_First()->rec);
        rec_Delete(*rec_obj1);
    } else {
        int rint = random() % 100;
        prlog("create new: "<<rint);
        CreateRecord(rint);
    }
}



// 
void sample::Main() {
    for (int i=0; i<5; i++) {
        CreateRecord(i);
    }
    prlog("fix 3/testing nogen")
    auto hashkey1=101;
    if (sample::FRec *rec_obj = ind_hashkey_Find(hashkey1)) {
        prlog("I found "<<rec_obj->rec <<" with hashkey "<<hashkey1);
    }
    sample::MainLoop();
}
