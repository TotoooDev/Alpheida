#include <engine/timer.h>
#include <time.h>
#include <stdbool.h>

static bool init_timer = true;
static struct timespec first_time;

f32 timer_get_time_s() {
    if (init_timer) {
        clock_gettime(CLOCK_REALTIME, &first_time);
        init_timer = false;
    }

    struct timespec now;
    clock_gettime(CLOCK_REALTIME, &now);
    f32 seconds = (f32)(now.tv_sec - first_time.tv_sec);
    f32 nano_seconds = (f32)(now.tv_nsec - first_time.tv_nsec);
    f32 current = seconds + nano_seconds * 1e-9;
    return current;
}

f32 timer_get_time_ms() {
    return timer_get_time_s() * 1000.0f;
}

f32 timer_get_time_us() {
    return timer_get_time_ms() * 1000.0f;
}

