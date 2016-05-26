//
//  macho_helper_path.c
//  macho_helper
//
//  Created by 黄涛 on 16/5/25.
//  Copyright © 2016年 com.turing. All rights reserved.
//

#include "stdlib.h"
#include "string.h"
#include "macho_helper_path.h"
#include "macho_helper.h"


int mh_parse_file_path (MachoHelper *mh, const char* path)
{
    unsigned long len = strlen(path) ;
    
    mh->path = (char*) malloc (sizeof(char)*(len+64));
    
    if (mh->path == NULL) {
        printf ("\nmalloc mh->path failed! %ld bytes",len+1);
        return -1 ;
    }
    
    /*
    todo:支持从.app的路径直接读取二进制文件
     
    if (0 != strcmp(path, ".app") &&
        (path + len) == (strstr(path,".app") + 4 + 1)
        ) {
        
    } else {
        strncpy(mh->path, path, len);
        mh->path[len] = '\0' ;
    }
     */
    
    strncpy(mh->path, path, len);
    mh->path[len] = '\0' ;
    return 0 ;
}