/*
Author: Samuel Wasko
Date: 09/12/2021
Decscription: This is an example of how to use
   scanf to read various types of data from the user.
   Program takes double values for wall dimensions and
   outputs the amount of paint needed depending on feet
   covered per gallon of paint.
*/
#include <stdio.h>
#include <math.h>                  // Note: Needed for math functions in part (3)

int main(void) {
   double wallHeight;
   double wallWidth;
   double wallArea;
   const double sqFeetPerGal = 350;
   double galsNeeded;
   int cansNeeded;

   printf("Enter wall height (feet):\n");
   scanf("%lf", &wallHeight);
   
   printf("Enter wall width (feet):\n");
   scanf("%lf", &wallWidth);
   
   // Calculate and output wall area
   wallArea = wallWidth * wallHeight;                
   printf("Wall area: %0.2lf square feet\n", wallArea);       
   
   //Calculate and output the amount of paint in gallons needed to paint the wall
   galsNeeded = wallArea / sqFeetPerGal;
   printf("Paint needed: %0.2lf gallons\n", galsNeeded);

   //Calculate and output the number of 1 gallon cans needed to paint the wall, rounded up to nearest integer
   cansNeeded = (int)ceil(galsNeeded);
   printf("Cans needed: %d can(s)\n", cansNeeded);

   return 0;
}