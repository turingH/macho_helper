//
//  macho_helper_path.h
//  macho_helper
//
//  Created by 黄涛 on 16/5/25.
//  Copyright © 2016年 com.turing. All rights reserved.
//

#ifndef macho_helper_path_h
#define macho_helper_path_h

#include <stdio.h>

typedef struct macho_helper MachoHelper;

int mh_parse_file_path (MachoHelper *mh, const char* path) ;

#endif /* macho_helper_path_h */
