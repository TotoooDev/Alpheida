#include <timer.h>
#include <time.h>

float timer_get_time_s() {
    return (float)clock() / CLOCKS_PER_SEC;
}

float timer_get_time_ms() {
    return timer_get_time_s() * 0.001f;
}

float timer_get_time_us() {
    return timer_get_time_ms() * 0.001f;
}

