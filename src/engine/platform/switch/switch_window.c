#include <engine/platform/config.h>

#ifdef SHRIMP_SWITCH

// my honest reaction: https://www.youtube.com/watch?v=jO8o5LLmpR8
// but the code between linux and switch are identical since both use sdl2
// so i might just copy-paste it lol

#define SHRIMP_LINUX
#include "../linux/linux_window.c"
#undef SHRIMP_LINUX

#endif
