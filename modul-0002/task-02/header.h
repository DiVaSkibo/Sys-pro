#define _GNU_SOURCE
#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <time.h>

clock_t t;

void sighandler(int);

int scan_dir(char*);
int find_signature(int, char*);
