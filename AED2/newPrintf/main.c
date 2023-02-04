#define _GNU_SOURCE //cause stdio.h to include vasprintf
#include <stdio.h> //printf, vasprintf
#include <stdarg.h> //va_start, va_end
#include <stdlib.h> //system, free
#include <assert.h>

int system_w_printf(char const *fmt, ...) \
__attribute__ ((format (printf,1,2)));

int system_w_printf(char const *fmt, ...){
char *cmd;
va_list argp;
va_start(argp, fmt);
vasprintf(&cmd, fmt, argp);
va_end(argp);
int out= system(cmd);
free(cmd);
return out;
}

int main(int argc, char **argv){
assert(argc == 3);
return system_w_printf("echo %s %s", argv[1], argv[2]);
}