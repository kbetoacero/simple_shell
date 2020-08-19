#ifndef S_SHELL
#define S_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>
#include <linux/limits.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>

void _prompt(void);
char *rec_env(char *buf);
/*void han_cmd_func(int sig);*/
char **splt(char *raw_cmd, char *limit);
/* void main_chk(int pid, char **cmd);*/

#endif  /* S_SHELL */
