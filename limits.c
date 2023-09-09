#include <stdio.h>
#include <sys/resource.h>

int main() {
  // rlimits is the key to solving this problem
  // go to the man page for getrlimits
  // In order to use the get r limits we need to use the standard library and
  // resource.h we need to use the rlimit structure.
  struct rlimit lim;
  getrlimit(RLIMIT_STACK, &lim);
  printf("stack size: %ld\n", lim.rlim_cur);
  // Max number of processes
  getrlimit(RLIMIT_NPROC, &lim);
  printf("process limit: %ld\n", lim.rlim_cur);
  // Max number of file descriptors
  getrlimit(RLIMIT_NOFILE, &lim);
  printf("max file descriptors: %ld\n", lim.rlim_cur);
  return 0;
}
