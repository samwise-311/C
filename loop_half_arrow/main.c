#include <stdio.h>

/*
* Author: Samuel Wasko
* Date: Sun 26 Sep 2021 09:45:19 PM MDT
* Description: Using Loops to draw a half arrow
*/
int main(void) {
   int arrowBaseHeight = 0;
   int arrowBaseWidth = 0;
   int arrowHeadWidth = 0;
   int rc = 0;
   int rc1 = 0;
   int rc2 = 0;
   
   printf("Enter arrow base height:\n");
   rc = scanf("%d", &arrowBaseHeight);
   
   printf("Enter arrow base width:\n");
   rc1 = scanf("%d", &arrowBaseWidth);
   
   printf("Enter arrow head width:\n");
   rc2 = scanf("%d", &arrowHeadWidth);
   printf("\n");
   
   /* Error handling for non-integer input */
   if (rc == 0||rc1 == 0||rc2 == 0) {
      printf("Error: Unrecognized input, please enter only integer values.\n");
   }

   /* Prompt user for a valid arrow head value */
   if (arrowHeadWidth <= arrowBaseWidth) {
      printf("Error: Arrow head width must be greater than base width!\nTry Again...\n");
      arrowHeadWidth = 0;
      printf("\nEnter arrow head width:\n");
      rc2 = scanf("%d", &arrowHeadWidth);
      printf("\n");
      
   }
   /* Nested loop to draw arrow base to widtha and height */
   for (int i=0;i<arrowBaseHeight;i++) {
      for (int j=0;j<arrowBaseWidth;j++) {
            printf("*");
      }
      printf("\n");
   }

/* Nested loop to draw arrow head to width and descend to nothing */
   for (int i = 0; i < arrowHeadWidth; i++) {
        for (int k = 0; k < arrowHeadWidth - i; k++) {
            printf("*");
         }
            printf("\n");
   }

   
   return 0;
}