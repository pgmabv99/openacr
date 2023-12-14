// Copyright (C) 2023 AlgoRND
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
// Target: sandbox (exe) -- Sandbox - sandbox management tool
// Exceptions: yes
// Header: include/sandbox.h
//

#include "include/algo.h"
#include "include/gen/sandbox_gen.h"
#include "include/gen/sandbox_gen.inl.h"

namespace sandbox { // update-hdr
    // Dear human:
    //     Text from here to the closing curly brace was produced by scanning
    //     source files. Editing this text is futile.
    //     To refresh the contents of this section, run 'update-hdr'.
    //     To convert this section to a hand-written section, remove the word 'update-hdr' from namespace line.

    // -------------------------------------------------------------------
    // cpp/sandbox.cpp
    //
    void ResetSandbox(sandbox::FSandbox &sandbox);
    void AcrApply(algo::strptr script, algo::strptr op);
    void ListSandbox();
    void Main();
}
