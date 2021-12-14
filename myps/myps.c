/* 
 * Author: Samuel Wasko
 * Tue 07 Dec 2021 02:37:03 PM MST
 * Description: myps.c - The myps tool navigates to each PID directory in /proc (or other specified
 * directory), opens the stat file, and extracts the required fields to build a ProcEntry struct.
 * User specified filters are used to sort and filter the data.
 */

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

/* initialization for functions*/
static int procFilter(const struct dirent *current);
static int pidSort(const void *a, const void *b);
static int commSort(const void *a, const void *b);
void printUsage(char *current);


int main (int argc, char * argv[]) {

	/* Allocate space for filepath on stack 
	 * and initialize filepath to empty string */
	char filePath[MAX_PATH_LENGTH];
	strcpy(filePath,"/proc");

	/* declaration of variables */
	int sortChosen = 0;  //1 for yes/0 for no
	char sortType = 'p';
	int zombieState;
	struct dirent **fileScanner;
	int opt;
	int n;

	/* handle command line args */
	while ((opt = getopt(argc, argv, "hpczd:")) != -1) {
		switch (opt){
		case 'h':
			printUsage(argv[0]);
			exit(0);
			break;
		case 'p':
			if (sortChosen == 1) {
				fprintf(stderr,"Usage: %s [-d <path>] [-p] or [-c]\n", argv[0]);
				return 0;
			}
			sortChosen = 1;
			sortType = 'p';
			break;
		case 'c':
			if (sortChosen == 1) {
				fprintf(stderr,"Usage: %s [-d <path>] [-p] or [-c]\n", argv[0]);
				return 0;
			}
			sortChosen = 1;
			sortType = 'c';
			break;
		case 'z':
			zombieState = 1;
			break;
		case 'd':
			strncpy(filePath, optarg, MAX_PATH_LENGTH);
			break;
		default:
			printUsage(argv[0]);
			exit(1);
			break;
		}
	}

	/*error check*/
	errno = 0;
	n = scandir(filePath, &fileScanner, procFilter, alphasort);
	if (n < 0) {
		perror("scandir: ");
		exit(1);
	}

	if (n == 0) {
		fprintf(stdout, "Couldn't find a processes\n");
		return 0;
	}

	ProcEntry ** myprocs = (ProcEntry **) (malloc(sizeof(ProcEntry *) * n));


	char procFile[MAX_PATH_LENGTH];
	int mLength; /* Max pid Length */
	mLength = MAX_PATH_LENGTH - strlen(filePath) - 7;
	for (int i = 0; i < n; i++) {

		strcpy(procFile, filePath);
		strcat(procFile, "/");
		strncat(procFile, fileScanner[i]->d_name, mLength);
		strcat(procFile, "/stat");

		myprocs[i] = CreateProcEntryFromFile(procFile);


		if (myprocs[i] == NULL) {
			fprintf(stderr, "ERROR: Failed to create ProcEntry\n");
			for (int j = 0; j < n; j++)  {
				free(fileScanner[j]);
				DestroyProcEntry(myprocs[i]);
			}
			free(fileScanner);
			free(myprocs);
			exit(3);
		}

	}
    /* free array */
	for (int i = 0; i < n; i++)  {
		free(fileScanner[i]);
	}
    /* free array itself */
	free(fileScanner);

    /*check for sorting instructions */
	if (sortType == 'p') {
        /*sort by proc*/
		qsort(myprocs, n, sizeof(ProcEntry *), pidSort);
	} else if (sortType == 'c') {
        /*sort by comm*/
		qsort(myprocs, n, sizeof(ProcEntry *), commSort);
	} else {
		fprintf(stderr, "ERROR: Failed to sort chosen file\n");
		for (int i = 0; i < n; i++)  {
			DestroyProcEntry(myprocs[i]);
		}
        /* free myprocs */
		free(myprocs);
		exit(4);
	}

	/* Titles Output */
	fprintf(stdout,"%7s %7s %5s %5s %5s %7s %-25s %-20s\n","PID","PPID","STATE","UTIME","STIME","THREADS","CMD","STAT_FILE");

	for(int i = 0; i < n; i++) {
		if (zombieState == 1 && myprocs[i]->state != 'Z') {
			continue;
		}
        /* print myprocs entries */
		PrintProcEntry(myprocs[i]);
	}
    /* destroy myprocs entries */
	for (int i = 0; i < n; i++)  {
		DestroyProcEntry(myprocs[i]);
	}
    /* free myprocs */
	free(myprocs);
	return 0;
}
/* 
 *
 *procFilter function to specify wanted values in /proc data
 *
 */
static int procFilter (const struct dirent *current) {
	if ((current->d_type != DT_DIR) || !isdigit(current->d_name[0])) {
		return 0;
	}
	return 1;
}
/* 
 *
 *pidSort function to compare and sort values(a&b) in STAT_FILE data
 *
 */
static int pidSort(const void *a, const void *b) {
	ProcEntry *f = *(ProcEntry **)a;
	ProcEntry *s = *(ProcEntry **)b;
	int ret = f->process_id - s->process_id;
	return ret;
}
/* 
 *
 *commSort function to compare and sort values in CMD data
 *
 */
static int commSort(const void *a, const void *b) {
	ProcEntry *f = *(ProcEntry **)a;
	ProcEntry *s = *(ProcEntry **)b;
	return strcmp(f->comm, s->comm);
}
/* 
 *
 *printUsage function takes char pointer to display usage options to console
 *
 */
void printUsage(char *current)
{
	fprintf(stderr, "Usage: %s [-d <path>] [-p] [-c] [-z] [-h]\n", current);
	fprintf(stderr, "\t-d <path> Directory containing proc entries (default: /proc)\n");
	fprintf(stderr, "\t-p        Display proc entries sorted by pid (default)\n");
	fprintf(stderr, "\t-c        Display proc entries sorted by command lexicographically\n");
	fprintf(stderr, "\t-z        Display ONLY proc entries in the zombie state\n");
	fprintf(stderr, "\t-h        Display this help message\n");
}