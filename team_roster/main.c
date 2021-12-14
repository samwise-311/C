

#include <stdio.h>

const int TEAM_SIZE = 5;

void PrintMenu(void)
{
   printf("MENU\n");
   printf("u - Update player rating\n");
   printf("a - Output players above a rating\n");
   printf("r - Replace player\n");
   printf("o - Output roster\n");
   printf("q - Quit\n\n");
   printf("Choose an option:\n");
}

int main(void)
{

   /* Declare arrays matching team size */
   int jerseyNums[TEAM_SIZE];
   int ratings[TEAM_SIZE];
   char userIn;

   /* Read jersey no. and rating, store in array */
   for (int i = 0; i < TEAM_SIZE; i++)
   {
      int rc = 0;
      while (rc == 0)
      {
         printf("Enter player %d's jersey number:\n", (i + 1));
         rc = scanf("%d", &jerseyNums[i]);

         printf("Enter player %d's rating:\n", (i + 1));
         rc = scanf("%d", &ratings[i]);
         printf("\n");

         while (getchar() != '\n')
            ;
      }
   }

   /* Display Roster */
   void PrintRoster(void){
      printf("ROSTER\n");
      for (int i = 0; i < TEAM_SIZE; i++)
      {
         printf("Player %d -- Jersey number: %d, Rating: %d\n", (i + 1), jerseyNums[i], ratings[i]);
      }
      printf("\n");
      PrintMenu();
      scanf("%s", &userIn);
   }

   PrintRoster();

   /*While conditions for the menu choices */
   while (userIn != -1){
   while (userIn == 'q')
   {
      printf("Goodbye!");
      return 0;
 
   }
   while (userIn == 'o')
   {
      printf("ROSTER\n");
      for (int i = 0; i < TEAM_SIZE; i++)
      {
         printf("Player %d -- Jersey number: %d, Rating: %d\n", (i + 1), jerseyNums[i], ratings[i]);
      }
      printf("\n");
      PrintMenu();
      scanf("%s", &userIn);

   }
   while (userIn == 'r')
   {
      int numChange = 0;
      int newNumber = 0;
      int newRating = 0;
      printf("Enter a jersey number:\n");
      scanf("%d", &numChange);
      printf("Enter a new jersey number:\n");
      scanf("%d", &newNumber);
      printf("Enter a rating for the new player:\n");
      scanf("%d", &newRating);

      for (int i = 0; i < TEAM_SIZE; i++)
      {
         if (jerseyNums[i] == numChange)
         {
            jerseyNums[i] = newNumber;
            ratings[i] = newRating;
         }
      }
      PrintMenu();
      scanf("%s", &userIn);
   }

   while (userIn == 'u')
   {
      int numChange = 0;
      int newRating = 0;
      printf("Enter a jersey number:\n");
      scanf("%d", &numChange);
      printf("Enter a new rating for the player:\n");
      scanf("%d", &newRating);
   
    for (int i = 0; i < TEAM_SIZE; i++) {
      if (jerseyNums[i] == numChange) {
         ratings[i] = newRating;
      }
   }
   PrintMenu();
   scanf("%s", &userIn);

   }

while (userIn == 'a') {
   int ratingThresh = 0;
   printf("Enter a rating:\n");
   scanf("%d", &ratingThresh);
   printf("ABOVE %d\n", ratingThresh);

for (int i = 0; i < TEAM_SIZE; i++) {
      if (ratings[i] >= ratingThresh) {
         printf("Player %d -- Jersey number: %d, Rating: %d\n", (i+1), jerseyNums[i], ratings[i]);
      }
   }
   printf("\n");
PrintMenu();
scanf("%s", &userIn);
}
   }

//Not Working yet...
/*while (userIn != 'q' || userIn != 'o' || userIn != 'r' || userIn != 'a' || userIn != 'u') {
 printf ("Error: Unknown option selected\n");
 PrintMenu();
 scanf("%s", &userIn);
*/

}
