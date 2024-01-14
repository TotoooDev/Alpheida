#include <timer.h>
#include <time.h>

f32 timer_get_time_s() {
    return (f32)clock() / CLOCKS_PER_SEC;
}

f32 timer_get_time_ms() {
    return timer_get_time_s() * 1000.0f;
}

f32 timer_get_time_us() {
    return timer_get_time_ms() * 1000.0f;
}

