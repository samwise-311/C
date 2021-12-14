/* 
 * Author: Samuel Wasko
 * Tue 07 Dec 2021 02:37:03 PM MST
 * Description: ProcEntry.c - represents a ProcEntry struct and its functions.
 * A ProcEntry is a collection of data from the /proc file system.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "ProcEntry.h"

/*
 *
 *  CreateProcEntry(void) function creates empty ProcEntry
 *  and returns pointer to entries struct
 */
ProcEntry * CreateProcEntry(void) {
	ProcEntry * newEntry = (ProcEntry*)malloc(sizeof(ProcEntry));
	// Allocate newEntry
	if (newEntry == NULL) {
		return NULL;
	}
	//intialize variables
	newEntry->process_id = 0;
	newEntry->parent_process_id = 0;
	newEntry->state = '\0';
	newEntry->utime = 0;
	newEntry->stime = 0;
	newEntry->number_of_threads = 0;
	newEntry->comm = NULL;
	newEntry->path = NULL;

    /*return new proc entry */
    return newEntry;
}

/*
 *
 * CreateProcEntryFromFile(const char statFile[]) takes a char array parameter referring
 *  to the stat file and creates ProcEntry returning a pointer to the entry
 */
ProcEntry * CreateProcEntryFromFile(const char statFile[]) {

	/* Open and validate file */
	FILE * datafile = fopen(statFile, "r");
	if (datafile == NULL) {
		perror("fopen");
		return NULL;
	}
	
	/* Create and validate ProcEntry */
	ProcEntry  * newEntry = (ProcEntry *)malloc(sizeof(ProcEntry));
	if (newEntry == NULL) {
		fprintf(stderr, "ERROR: Unable to allocate memory for ProcEntry!\n");
		return NULL;
	}

	newEntry->path = (char *)malloc(sizeof(char) * (strlen(statFile) + 1));
	if(newEntry->path == NULL) {
		fprintf(stderr, "ERROR: Failed to allocate path\n");
		return NULL;
	}
	strncpy(newEntry->path, statFile, strlen(statFile) + 1);
    
    /*  Temporary variables for conditions while filling struct */
	int numRead;
	//int entryCount = 0;

		for(int i = 1; i <= 20; i++) {
			switch (i) {
/*p_id*/	case 1: ;
			    numRead = fscanf(datafile, " %d", &newEntry->process_id);
			    if (numRead != 1) {
			    	fprintf(stderr, "ERROR: Failed to read in process_id\n");
			    	return NULL;
			    }
			break;
/*comm*/	case 2: ;
			    char tempString[1000];
			    numRead = fscanf(datafile, " %1000s", tempString);
			    if (numRead != 1) {
			    	fprintf(stderr, "ERROR: Failed to read in Comm\n");
			    	return NULL;
			    }
                /* allocate comm */
			    newEntry->comm = (char *)malloc(sizeof(char) * (strlen(tempString) + 1));
			    if(newEntry->comm == NULL) {
			    	fprintf(stderr, "ERROR: Failed to allocate Comm\n");
			    	return NULL;
			    }
			    strncpy(newEntry->comm, tempString, strlen(tempString) + 1);
			break;
/*state*/	case 3: ;
			    numRead = fscanf(datafile, " %c", &newEntry->state);
			    if (numRead != 1) {
			    	fprintf(stderr, "ERROR: Failed to read in state\n");
			    	return NULL;
			    }
			break;
/*pp_id*/	case 4:
				numRead = fscanf(datafile, " %d", &newEntry->parent_process_id);
				if (numRead != 1) {
					fprintf(stderr, "ERROR: Failed to read in parent_process_id\n");
					return NULL;
				}
			break;
/*utime*/	case 14:
				numRead = fscanf(datafile, " %lu", &newEntry->utime);
				if (numRead != 1) {
					fprintf(stderr, "ERROR: Failed to read in utime (user)\n");
					return NULL;
				}
			break;
/*stime*/	case 15:
				numRead = fscanf(datafile, " %lu", &newEntry->stime);
				if (numRead != 1) {
					fprintf(stderr, "ERROR: Failed to read in stime (kernel)\n");
					return NULL;
				}
			break;
/*threads*/	case 20:
				numRead = fscanf(datafile, " %ld", &newEntry->number_of_threads);
				if (numRead != 1) {
					fprintf(stderr, "ERROR: Failed to read in number_of_threads from processor\n");
					return NULL;
				}
			break;
/*default*/	default:
				fscanf(datafile, " %*u");
			break;
			}
		}
	
    /* close datafile */
	fclose(datafile);
	return newEntry;
}

/* 
 * 
 * DestroyProcEntry(ProcEntry * entry) takes a pointer to an entry as a parameter
 * and destroys ProcEntry.
 */
void DestroyProcEntry(ProcEntry *entry) {
    if (entry == NULL) {
        return;
    }
    //FREE MEMORY...eliminate leakage possibility :)
    free(entry->comm);
    free(entry->path);
    free(entry);
}

/*
 * 
 * PrintProcEntry(ProcEntry *entry) was a given function to print out proc entries
 * from ProcEntry pointer parameter.
 */
void PrintProcEntry(ProcEntry *entry) {
	unsigned long int utime = entry->utime / sysconf(_SC_CLK_TCK);
	unsigned long int stime = entry->stime / sysconf(_SC_CLK_TCK);
	fprintf(stdout, "%7d %7d %5c %5lu %5lu %7ld %-25s %-20s\n",
			entry->process_id,
			entry->parent_process_id,
			entry->state,
			utime,
			stime,
			entry->number_of_threads,
			entry->comm,
			entry->path);
}