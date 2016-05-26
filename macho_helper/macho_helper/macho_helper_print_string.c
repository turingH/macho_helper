//
//  macho_helper_print_string.c
//  macho_helper
//
//  Created by 黄涛 on 16/5/26.
//  Copyright © 2016年 com.turing. All rights reserved.
//


#include "macho_helper_print_string.h"
#include <assert.h>
#include <mach-o/loader.h>

const char* mh_load_commnad_strmap (int id)
{
    switch (id) {
        case 0x1:
            return "LC_SEGMENT";
        case 0x2:
            return "LC_SYMTAB";
        case 0x3:
            return "LC_SYMSEG";
        case 0x4:
            return "LC_THREAD";
        case 0x5:
            return "LC_UNIXTHREAD";
        case 0x6:
            return "LC_LOADFVMLIB";
        case 0x7:
            return "LC_IDFVMLIB";
        case 0x8:
            return "LC_IDENT";
        case 0x9:
            return "LC_FVMFILE";
        case 0xa:
            return "LC_PREPAGE";
        case 0xb:
            return "LC_DYSYMTAB";
        case 0xc:
            return "LC_LOAD_DYLIB";
        case 0xd:
            return "LC_ID_DYLIB";
        case 0xe:
            return "LC_LOAD_DYLINKER";
        case 0xf:
            return "LC_ID_DYLINKER";
        case 0x10:
            return "LC_PREBOUND_DYLIB";
        case 0x11:
            return "LC_ROUTINES";
        case 0x12:
            return "LC_SUB_FRAMEWORK";
        case 0x13:
            return "LC_SUB_UMBRELLA";
        case 0x14:
            return "LC_SUB_CLIENT";
        case 0x15:
            return "LC_SUB_LIBRARY";
        case 0x16:
            return "LC_TWOLEVEL_HINTS";
        case 0x17:
            return "LC_PREBIND_CKSUM";
        case (0x18 | LC_REQ_DYLD):
            return "LC_LOAD_WEAK_DYLIB";
        case 0x19:
            return "LC_SEGMENT_64";
        case 0x1a:
            return "LC_ROUTINES_64";
        case 0x1b:
            return "LC_UUID";
        case (0x1c | LC_REQ_DYLD) :
            return "LC_RPATH";
        case 0x1d:
            return "LC_SEGMENT_SPLIT_INFO";
        case 0x1e:
            return "LC_SEGMENT";
        case (0x1f | LC_REQ_DYLD):
            return "LC_REEXPORT_DYLIB";
        case 0x20:
            return "LC_LAZY_LOAD_DYLIB";
        case 0x21:
            return "LC_ENCRYPTION_INFO";
        case 0x22:
            return "LC_DYLD_INFO";
        case (0x22|LC_REQ_DYLD):
            return "LC_DYLD_INFO_ONLY";
        case (0x23 | LC_REQ_DYLD):
            return "LC_LOAD_UPWARD_DYLIB";
        case 0x24:
            return "LC_VERSION_MIN_MACOSX";
        case 0x25:
            return "LC_VERSION_MIN_IPHONEOS";
        case 0x26:
            return "LC_FUNCTION_STARTS";
        case 0x27:
            return "LC_DYLD_ENVIRONMENT";
        case (0x28|LC_REQ_DYLD):
            return "LC_MAIN";
        case 0x29:
            return "LC_DATA_IN_CODE";
        case 0x2a:
            return "LC_SOURCE_VERSION";
        case 0x2b:
            return "LC_DYLIB_CODE_SIGN_DRS";
        case 0x2c:
            return "LC_ENCRYPTION_INFO_64";
        case 0x2d:
            return "LC_LINKER_OPTION";
        case 0x2e:
            return "LC_LINKER_OPTIMIZATION_HINT";
        case 0x30:
            return "LC_VERSION_MIN_WATCHOS";
            
        default:
            assert(0) ;
            break;
    }
    return "" ;
}