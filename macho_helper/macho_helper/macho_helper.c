//
//  macho_helper.c
//  macho_helper
//
//  Created by 黄涛 on 16/5/25.
//  Copyright © 2016年 com.turing. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <assert.h>


#include "macho_helper.h"
#include "macho_helper_path.h"


MachoHelper * mh_malloc ()
{
    return (MachoHelper *) malloc(sizeof(MachoHelper)) ;
}

int mh_init (MachoHelper *mh)
{
    memset (mh,0,sizeof(MachoHelper));
    return 0 ;
}

int mh_open(MachoHelper *mh, const char * path)
{
    if (mh_parse_file_path(mh, path) < 0){
        printf("\nmh_open failed in mh_parse_file_path,%s",path);
        return -1;
    }
    
    FILE *fp = fopen(mh->path, "r");
    
    if (!fp) {
        printf("\nmh_open failed in fopen,%s",mh->path);
        return -1;
    }
    
    struct stat s;
    if (stat(mh->path,&s) < 0) {
        printf("\nmh_open failed in stat,%s",mh->path);
        return -1;
    }
    
    mh->size = s.st_size ;
    mh->macho_data = malloc(sizeof(char)*s.st_size);
    
    if (NULL == mh->macho_data) {
        printf("\nmh_open failed in malloc,%lld",s.st_size);
        return -1 ;
    }
    
    if (fread(mh->macho_data, 1, mh->size, fp) != mh->size) {
        printf("\nmh_open failed in fread,%lld",mh->size);
        return -1 ;
    }
    
    if (fclose(fp) != 0) {
        printf("\nmh_open failed in fclose");
        return -1 ;
    }
    return 0 ;
}

MachoHelper * mh_ez_open (const char* path)
{
    MachoHelper * pmh ;
    
    pmh = mh_malloc () ;
    
    if (!pmh) {
        printf ("\nmh_malloc failed") ;
        return NULL ;
    }
    
    if (mh_init (pmh) < 0) {
        printf ("\nmh_init failed") ;
        return NULL ;
    }
    
    if ( mh_open(pmh,path) < 0) {
        printf ("\nmh_init failed") ;
        return NULL ;
    }
    
    return pmh ;
}



int mh_is_fat (MachoHelper* mh)
{
    assert (mh && mh->macho_data);
    struct fat_header* fheader = (struct fat_header*)mh->macho_data;
    if (fheader->magic == FAT_CIGAM || fheader->magic == FAT_MAGIC) {
        return fheader->magic;
    }else{
        return 0 ;
    }
    assert(0) ;
}

int mh_is_mh (MachoHelper* mh)
{
    assert (mh && mh->macho_data);
    struct mach_header *mheader = (struct mach_header*)mh->macho_data;
    if (MH_MAGIC == mheader->magic ||
        MH_CIGAM == mheader->magic ||
        MH_MAGIC_64 == mheader->magic ||
        MH_CIGAM_64 == mheader->magic
        ) {
        return mheader->magic ;
    } else {
        return 0 ;
    }
    assert(0) ;
}

int mh_is_32 (MachoHelper* mh)
{
    assert (mh && mh->macho_data);
    struct mach_header *mheader = (struct mach_header*)mh->macho_data;
    switch (mheader->magic)
    {
        case MH_MAGIC:
        case MH_CIGAM:
            return 1;
        case MH_MAGIC_64:
        case MH_CIGAM_64:
           return 0 ;
        default:
            printf("\nmh is not a macho file");
            assert(0);
    }
    assert(0) ;
}

struct mach_header const* mh_macho_header (MachoHelper* mh)
{
    assert (mh && mh->macho_data);
    return (struct mach_header const*)mh->macho_data;
}

struct load_command * mh_get_all_load_commands(MachoHelper* mh,int copy)
{
    struct mach_header const *mheader = mh_macho_header(mh);
    struct load_command* lcs = NULL ;
    if (copy){
        lcs = malloc (sizeof(struct load_command)*mheader->sizeofcmds);
        if (!lcs) {
            printf("\nmh_get_all_load_commands failed in malloc,siez %lu", sizeof(struct load_command)*mheader->sizeofcmds ) ;
            return NULL ;
        }
    
        memset(lcs,0,sizeof(struct load_command)*mheader->sizeofcmds);
        memcpy(lcs,(void*)mheader+sizeof(struct mach_header),sizeof(struct load_command)*mheader->sizeofcmds) ;
    }else{
        lcs = (struct load_command* )((void*)mheader+sizeof(struct mach_header)) ;
       
    }
    return lcs;
}

void mh_print_load_commands(MachoHelper *mh)
{
    struct load_command const *cur = mh_get_all_load_commands(mh, 0);
    assert(cur) ;
    uint32_t i ;
    printf ("\nprint all load commands\n") ;
    for (i = 0; i < mh_macho_header(mh)->sizeofcmds; i++) {
        printf("\n%d\t:%s\t\t:%d",i,mh_load_commnad_strmap(cur->cmd),cur->cmdsize);
        cur = (struct load_command const *)(((char const*)cur)+cur->cmdsize);
    }
    
}
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
