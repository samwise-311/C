#define _GNU_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <errno.h>
#include "ProcEntry.h"

#define MAX_PATH_LENGTH 4096

int main (void) {
char * current = "t";
fprintf(stdout,"TESTING...123");
printUsage(current);
return 0;
}
void printUsage(char *current)
{
   
   fprintf(stderr, "Usage: %s [-d <path>] [-p] [-c] [-z] [-h]\n", current);
   fprintf(stderr, "\t-d <path> Directory containing proc entries (default: /proc)\n");
   fprintf(stderr, "\t-p        Display proc entries sorted by pid (default)\n");
   fprintf(stderr, "\t-c        Display proc entries sorted by command lexicographically\n");
   fprintf(stderr, "\t-z        Display ONLY proc entries in the zombie state\n");
   fprintf(stderr, "\t-h        Display this help message\n");
}