#pragma once
/*-------------------------------------------------------------------------------------------
 * qblocks - fast, easily-accessible, fully-decentralized data from blockchains
 * copyright (c) 2018, 2019 TrueBlocks, LLC (http://trueblocks.io)
 *
 * This program is free software: you may redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version. This program is
 * distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details. You should have received a copy of the GNU General
 * Public License along with this program. If not, see http://www.gnu.org/licenses/.
 *-------------------------------------------------------------------------------------------*/
/*
 * Parts of this file were generated with makeClass. Edit only those parts of the code
 * outside of the BEG_CODE/END_CODE sections
 */
#include "acctlib.h"

// BEG_ERROR_DEFINES
// END_ERROR_DEFINES

class COptions : public COptionsBase {
  public:
    // BEG_CODE_DECLARE
    CAddressArray addrs;
    bool generate;
    // END_CODE_DECLARE

    bool first;
    uint64_t parts;
    CAbiArray abiList;
    string_q classDir;
    string_q prefix;

    COptions(void);
    ~COptions(void);

    bool parseArguments(string_q& command) override;
    void Init(void) override;

    bool isToken(void) const {
        return prefix % "tokenlib";
    }
    bool isWallet(void) const {
        return prefix % "walletlib";
    }
    bool isBuiltIn(void) const {
        return isToken() || isWallet();
    }
    void handle_generate(void);
    void convertFromSol(const address_t& a);
};

//-----------------------------------------------------------------------
extern string_q getPrefix(const string_q& in);
