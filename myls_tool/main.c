/* 
 * Author: Luke Hindman
 * Date: Thu 05 Nov 2020 08:10:44 AM PST
 * Description:  Adapted from the Simple Directory Lister Mark II example
 *    provided in the libc manual.
 * https://www.gnu.org/software/libc/manual/html_node/Simple-Directory-Lister-Mark-II.html
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define MAX_PATH_LENGTH 4096
#define UNUSED(x) (void)x

int showFilesOnly(const struct dirent *current)
{
    if (current->d_name[0] == '.' && current->d_type == DT_REG)
    {
        return 1;
    }
    else if (current->d_type == DT_REG)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int showAll(const struct dirent *current)
{
    UNUSED(current);
    return 1;
}

int noSort(const struct dirent **entryA, const struct dirent **entryB)
{
    UNUSED(entryA);
    UNUSED(entryB);
    return 0;
}
int reverseSort(const struct dirent **entryA, const struct dirent **entryB)
{
    UNUSED(entryA);
    UNUSED(entryB);
    return 0;
}
static int defaultFilter(const struct dirent *current)
{
    //check to omit showAll condition
    if (current->d_name[0] != '.')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char *argv[])
{
    struct dirent **eps;
    int n;
    int opt;

    /* Declare fileFilterFunction pointer */
    int (*fileFilterFunction)(const struct dirent *);
    fileFilterFunction = showFilesOnly;
    UNUSED(fileFilterFunction);

    /* Declare showAllFunction pointer */
    int (*showAllFunction)(const struct dirent *);
    showAllFunction = showAll;
    UNUSED(showAllFunction);

    /* Declare filterFuction pointer and set default to filter dots */
    int (*filterFunction)(const struct dirent *);
    filterFunction = defaultFilter;

    /* Declare sortFuction pointer and set default to nosort */
    int (*sortFunction)(const struct dirent **, const struct dirent **);
    sortFunction = noSort;

    /* Declare dirPath and set default to current directory */
    char dirPath[MAX_PATH_LENGTH];
    strcpy(dirPath, "./");

    /* Use getopt() to process command line args */
    while ((opt = getopt(argc, argv, "hafsd:r")) != -1)
    {
        switch (opt)
        {
        case 'h':
            printf("Usage: ./myls [-d <path>] [-s] [-a] [-f] [-r]\n");
            printf(" -d <path> Directory to list the contents of (default is current working directory)\n");
            printf(" -a        Display all files, including hidden files\n");
            printf(" -f        Display only regular files\n");
            printf(" -r        Display entries alphabetically in descending order\n");
            printf(" -s        Display entries alphabetically in ascending order\n");
            exit(0);
            break;
        case 'f':
            filterFunction = showFilesOnly;
            break;
        case 'a':
            filterFunction = showAll;
            break;
        case 'd':
            strncpy(dirPath, optarg, MAX_PATH_LENGTH);
            break;
        case 's':
            sortFunction = alphasort;
            break;
        case 'r':
            sortFunction = reverseSort;
            break;
        default:
            fprintf(stderr, "Error: Invalid option specified\n");
            fprintf(stderr, "Usage: %s [-d <path>] [-s] [-a] [-f] [-r]\n", argv[0]);
            break;
        }
    }

    /* Perform actual scan of the dirPath */
    errno = 0;
    n = scandir(dirPath, &eps, filterFunction, sortFunction);

    /* validate directory was opened successfully */
    if (n < 0)
    {
        perror("scandir: ");
        exit(1);
    }
    //if reverseSort is called print in reverse
    if (sortFunction == reverseSort) {
        while (n--) {
                        printf("%s\n", eps[n]->d_name);
                        free(eps[n]);
                }
                    //cleanup before exit
                    free(eps);
                    exit(0);
    }
    int cnt;
    for (cnt = 0; cnt < n; ++cnt)
    {
        fprintf(stdout, "%s\n", eps[cnt]->d_name);
    }
    
    /* cleanup memory */
    //array items
    for (int i = 0; i < n; i++)
    {
        free(eps[i]);
    }
    //array
    free(eps);

    return 0;
}
