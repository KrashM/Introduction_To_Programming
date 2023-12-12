#include <sys/resource.h>
#include <stdio.h>

int main(void){

    struct rlimit limit;

    getrlimit(RLIMIT_STACK, &limit);

    // rlimit.rlim_cur -> size in bytes
    // Alternative "ulimit -s" -> size in KB
    printf("\nStack Limit = %ld bytes and %ld bytes max\n", limit.rlim_cur, limit.rlim_max);

}