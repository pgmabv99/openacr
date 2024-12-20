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
// Header: cpp/myns/util.h
//

#include "include/algo.h"
#include "include/algo.h"
#include "include/myns.h"
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <iostream> // For std::cerr, std::endl
#include <fstream>  // For std::ofstream

#define MAX_EVENTS 10
#define PORT 8080
#define BUFFER_SIZE 512
#define CMD_SIZE 4

namespace myns
{

#define N_PART 3
    typedef struct
    {
        algo::Smallstr50 part_key;
        int amt;
        myns::FPart *part_obj;
    } part_data_t;



    void terminate_mcb();
    void test_delete();
    void scan_db_part_order();
    void scan_zd_db_order_via_sched1_fstep();
    void scan_zd_db_order_via_own_fstep();

    void test_update(algo::Smallstr50 part_key);
    void add_part();
    bool add_order(algo::Smallstr50 part_key, int quantity);
    void add_orders_manually();
    void fill_orders();
    void test_save();
    void cmd_execute(char cmd[CMD_SIZE]);

    // for tcp
    void tcp_listen();
    void tcp_accept();
    void tcp_read(myns::Client &client_obj);
    void tcp_close(myns::Client &client_obj);

    // for terminal
    void trm_listen();
    void trm_read();

}

namespace myns {
    extern int step_invocation_count;
    extern int version;
    extern bool step_display_flag;
}
// todo , make this into namespace
extern int step_invocation_count;
extern std::vector<myns::part_data_t> part_data;
