#define _GNU_SOURCE

#ifdef __APPLE__
    //no implementation
#else
#include <unistd.h>
#include <sys/syscall.h>

// this is a simple shim to disable vDSO use in libc

int clock_gettime(void * clk_id, void * tp) {
	return syscall(SYS_clock_gettime, clk_id, tp);
}

int gettimeofday(void * tv, void * tz) {
	return syscall(SYS_gettimeofday, tv, tz);
}

int time(void * tloc) {
	return syscall(SYS_time, tloc);
}

int nanosleep(const struct timespec *req, struct timespec *rem) {
        return syscall(SYS_nanosleep,req,rem);
}
#endif
