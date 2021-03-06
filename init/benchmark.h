#ifndef BENCHMARK_H
#define BENCHMARK_H

/* IO port for different exit points */
#define LINUX_EXIT_PORT 0xf4
#define FW_EXIT_PORT 0xf5

/* Exit point values */
#define FW_START    1
#define LINUX_START_FWCFG 2
#define LINUX_START_BOOT  3
#define LINUX_START_PVHBOOT  4
#define FW_DO_BOOT 5
#define LINUX_START_KERNEL 6
#define LINUX_START_USER 7

#endif