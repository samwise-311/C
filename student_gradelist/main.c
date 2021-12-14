/* File: main.c
 * Author: Sam Wasko
 * Date: Thu 04 Nov 2021 03:53:25 PM MDT
 * Description: main program for student database containing command line args
 * and use of student.h methods to create student list while properly allocating and freeing memory
 */
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "Student.h"

int main(int argc, char * argv[]) {

   if (argc != 2) {
      fprintf(stderr, "Usage: %s <gradebook.csv>\n", argv[0]);
      exit(1);
   }
 
   char * userFilename = argv[1];

   /* Open and validate file */
   FILE * datafile = fopen(userFilename, "r");
   if (datafile == NULL) {
      perror("fopen");
      exit(1);
   }

   /* INITIAL LIST INDEX SIZE */
   int initListSize = 8;

   /* Create studentlist/allocate memory for initially sized list */
   Student ** studentlist = (Student **) malloc(sizeof(Student *) * initListSize);
   if (studentlist == NULL) {
      fprintf(stderr,"Error: Unable to allocate memory for songlist");
      exit(1);
   }

   /*  Temporary variables for holding CSV fields */
   const int MAX_FIELD_SIZE = 256;
   char lastName[MAX_FIELD_SIZE];
   char firstName[MAX_FIELD_SIZE];
   int id;
   int score;
   int studentCount = 0;
   // FOR TESTING CONFIRMATION***
   //int studentsDestroyed = 0;
   int numRead;
   //reference for growing array printout
   int listSizeRef;

   while (!feof(datafile) && studentCount < initListSize) {
      numRead = fscanf(datafile, "%255[^,],%255[^,],%d,%d\n", lastName, firstName, &id, &score);
      if (numRead == 4) {
         studentlist[studentCount++] = CreateStudent(lastName, firstName, id, score);
         /* if studentlist is full double list size by reallocating --> learned in ECE 330 */
         if (!feof(datafile) && studentCount == initListSize) {
            listSizeRef = initListSize;
            initListSize *= 2;
            studentlist = (Student **) realloc(studentlist, sizeof(Student *) * initListSize);
            fprintf(stdout, "Growing Array: %d -> %d\n", listSizeRef, initListSize);
         }
      }
      else {
         fprintf(stderr, "Error: read %d of 4 when processing CSV!\n", numRead);
      }

   }
   fclose(datafile);
   fprintf(stdout, "Successfully loaded %d Students!\n", studentCount);

   /* sort sudentlist using the CompareStudents method! */
   qsort(studentlist, studentCount, sizeof(Student *), CompareStudents);

    /* Display the songList */
   for (int i = 0;i < studentCount; i++) {
      PrintStudent(studentlist[i]);
   }

    /* cleanup studentlist */
    for (int i = 0;i < studentCount; i++) {
      DestroyStudent(studentlist[i]);
   // FOR TESTING CONFIRMATION***
   // studentsDestroyed++;
   }
   free(studentlist);
   // FOR TESTING CONFIRMATION***
   //fprintf(stdout, "Successfully destroyed %d Students!\n", studentsDestroyed);

   return 0;
}