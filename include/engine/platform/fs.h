#ifndef FS_H
#define FS_H

#include <engine/platform/config.h>

#ifdef SHRIMP_SWITCH
    /**
     * Add "romfs:/" to the begginning of the string to access assets contained in romfs.
    */
    #define fs_get_path_romfs(path) "romfs:/"path

    /**
     * Add "sdmc:/switch/Alpheida" to the begginning of the string to access assets contained in the SD card.
    */
    #define fs_get_path(path) "sdmc:/switch/Alpheida/"path
#endif
#ifdef SHRIMP_WII
    #define fs_get_path_romfs(path) path
    #define fs_get_path(path) path
#endif
#ifdef SHRIMP_LINUX
    /**
     * Does nothing significant on Linux.
    */
    #define fs_get_path_romfs(path) path

    /**
     * Does nothing significant on Linux.
    */
    #define fs_get_path(path) path
#endif

#endif
