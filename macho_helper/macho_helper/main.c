//
//  main.c
//  macho_helper
//
//  Created by 黄涛 on 16/5/25.
//  Copyright © 2016年 com.turing. All rights reserved.
//

#include <stdio.h>
#include "macho_helper.h"

#define FilePath "/Users/turing/Downloads/IORegistryExplorer.app/Contents/MacOS/IORegistryExplorer"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    MachoHelper *mh = mh_ez_open(FilePath);
    uint32_t ret ;
    if ((ret = mh_is_fat(mh)) > 0) {
        printf ("\n%s is fat\nmagic numer is %x",FilePath,ret);
    }
    
    if ((ret = mh_is_mh(mh)) > 0) {
       printf ("\n%s is mach-o file\nmagic numer is %x",FilePath,ret);
    }
    
    ret = mh_is_32(mh) ;
    printf("\ncheck %s is 32bit mach-o file?\nresult:%d",FilePath,ret);
    
    
    struct load_command * lcs_copy = mh_get_all_load_commands(mh, 1) ;
    
    struct load_command * lcs_no_copy = mh_get_all_load_commands(mh, 0) ;
    
    printf ("\ntest:%s:%d",mh_load_commnad_strmap(lcs_copy->cmd),lcs_copy->cmdsize);
    printf ("\ntest:%s:%d",mh_load_commnad_strmap(lcs_no_copy->cmd),lcs_no_copy->cmdsize);
    
    mh_print_load_commands(mh);
    printf("\n") ;
    return 0;
}
