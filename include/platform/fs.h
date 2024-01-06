#ifndef FS_H
#define FS_H

#include <platform/config.h>

#ifdef SHRIMP_SWITCH
    #define fs_get_path_romfs(path) "romfs:/"path
    #define fs_get_path(path) "sdmc:/switch/Alpheida/"path
#endif
#ifdef SHRIMP_WII
    #define fs_get_path_romfs(path) path
    #define fs_get_path(path) path
#endif
#ifdef SHRIMP_LINUX
    #define fs_get_path_romfs(path) path
    #define fs_get_path(path) path
#endif

#endif
