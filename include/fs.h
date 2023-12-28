#ifndef FS_H
#define FS_H

#include <config.h>

#ifdef TOTO_SWITCH
    #define fs_get_path_romfs(path) path
    #define fs_get_path(path) "sdmc:/switch/Alpheida/"path
#else
    #define fs_get_path_romfs(path) path
    #define fs_get_path(path) path
#endif

#endif

