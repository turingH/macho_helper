//
//  macho_helper.h
//  macho_helper
//
//  Created by 黄涛 on 16/5/25.
//  Copyright © 2016年 com.turing. All rights reserved.
//

#ifndef macho_helper_h
#define macho_helper_h


#include <mach-o/nlist.h>
#include <mach-o/loader.h>
#include <mach/machine.h>
#include <mach-o/fat.h>
#include <sys/stat.h>
#include <mach-o/stab.h>

#include "macho_helper_print_string.h"

#ifdef __x86_64
    #define mach_header mach_header_64
    #define nlist nlist_64
    #define segment_command segment_command_64
    #define section section_64
#endif



static char g_buffer[1024] ;

struct macho_helper {
    void * macho_data ;
    char * path ;
    uint64_t size ;
};

typedef struct macho_helper MachoHelper;

MachoHelper * mh_malloc() ;

int mh_init (MachoHelper * mh);

int mh_open(MachoHelper * mh , const char * path);

MachoHelper * mh_ez_open(const char* path);

int mh_is_fat (MachoHelper* mh) ;

int mh_is_mh (MachoHelper* mh);

int mh_is_32 (MachoHelper* mh) ;

struct mach_header const* mh_macho_header (MachoHelper* mh) ;

struct load_command * mh_get_all_load_commands(MachoHelper* mh,int copy) ;

void mh_print_load_commands(MachoHelper *mh);

char * const mh_get_string_table(MachoHelper *mh,int copy);

int mh_get_command_by_cmd(MachoHelper *mh, int cmd, void* command, int szcommand) ;

struct nlist* mh_get_symbol_table(MachoHelper *mh,int copy) ;

#endif /* macho_helper_h */
