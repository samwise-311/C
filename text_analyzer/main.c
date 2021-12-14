/*
 * Author: Samuel Wasko
 * Date: Sun 10 Oct 2021 11:51:58 AM MDT
 * Description: Lab 07 Warmup Activity
 */

#include<stdio.h>
#include <string.h>
#include <ctype.h>

int charCount = 0;
int wordCount = 0;
char capString;

/*
 * Output string
 * userString - user's scanned in string
 */
void PrintString(char userString[]) {
printf("%s\n", userString);
}

/*
 * Get number of characters not including spaces
 * userString - user's scanned in string
 * int - returns count of non whitespace characters
 */
int GetNumOfNonWSCharacters(const char userString[]) {
   int count = 0;
      for (size_t i = 0; i < strlen(userString); i++) {
         if (userString[i] != ' ' && userString[i] != '\0') {
         count ++;
         }
      }
      return count;
}

/*
 * Get number of words in string using whitespace chatacters.
 * userString - user's scanned in string
 * int - returns count of words
 */
int GetNumOfWords(const char userString[]) {
   int count = 0;
   for (size_t i = 0; i < strlen(userString); i++) {
      if (userString[i] == ' ' || userString[i] == '.' || userString[i] == '!' || userString[i] == '?') {
         count++;
      }
      //double space marks sentence end/start
      if (userString[i] == ' ' && userString[i+1] == ' ') {
         count--;
      }
   }
   return count;
}

/*
 * Fix capitalization errors at sentence starts
 * userString - user's scanned in string
 */
void FixCapitalization(char userString[]) {
   for (size_t i = 0; i < strlen(userString); i++) {
      if ((i == 0 && userString[i] != ' ') || (userString[i] != ' ' && userString[i-1] == ' ' && userString[i-2] == ' ' && userString[i-3] == '.')) {
         if (userString[i] >= 'a' && userString[i] <= 'z') {
            userString[i] = toupper(userString[i]);
            //first attempt then I found out about toupper method
            //userString[i] = (('A'-'a') + ('a' - 'A'));
         }
      }
   }
   
   return;
}

/*
 * Replace all exclamation points with periods
 * userString - user's scanned in string
 */
void ReplaceExclamation(char userString[]) {
   for (size_t i = 0; i < strlen(userString); i++) {
      if (userString[i] == '!') {
         userString[i] = '.';
      }
   }
   return;
}

/*
 * Remove extra whitespace between sentences.
 * userString - user's scanned in string
 */
void ShortenSpace(char* userString) {
   //ugggh Feel like I am super close but nothing is changing
   char* d = userString;
   do {
      while (*d == ' ') {
      ++d;
      }
   }  while (*userString++ == *d++); 
   // for (size_t i = 0; i < strlen(userString); i++) {
   //    if (userString[i] == ' ' && userString[i-1] == ' ') {
   //    }
   // }
}

/*
 * Output menu for user options and call UDFs from above
 * userString - user's scanned in string
 */
void PrintMenu(char userString[])
{
   charCount = GetNumOfNonWSCharacters(userString);
   wordCount = GetNumOfWords(userString);
   //Didn't read that methods need to be called in PrintMenu
   //Once called in here my String was messed up without a temp String for each method
   // FixCapitalization(userString);
   // ReplaceExclamation(userString);
   // ShortenSpace(userString);

   printf("\nMENU\n");
   printf("c - Number of non-whitespace characters\n");
   printf("w - Number of words\n");
   printf("f - Fix capitalization\n");
   printf("r - Replace all !'s\n");
   printf("s - Shorten spaces\n");
   printf("q - Quit\n\n");
   printf("Choose an option:\n");
}

/*
 * Main method calling UDFs from above 
 */
int main(void) {

   /* Declare variables */
   const int MAX_INPUT_LENGTH = 256;
   char userString[MAX_INPUT_LENGTH];
   char menuChoice;
   char * inputRC;

   /* Prompt user for string */
   printf("Enter a sample text:\n");
   inputRC =  fgets(userString,MAX_INPUT_LENGTH,stdin);
   if (inputRC == NULL) {
      printf("An error occured while processing user input!\n");
      return 1;
   }

   /* [INITIAL]Output String and menu to user */
   printf("\nYou entered:\n");
   PrintString(userString);
   PrintMenu(userString);
   scanf("%c", &menuChoice);

/* while statements declaring menu option choices */
while (menuChoice != 'q') {
   switch (menuChoice) {
      case 'q':
         return 0;
         break;

      case 'c':
         printf("Number of non-whitespace characters: %d\n", charCount);
         PrintMenu(userString);
         scanf(" %c", &menuChoice);
         break;
    
      case'w':
         printf("Number of words: %d\n", wordCount);
         PrintMenu(userString);
         scanf(" %c", &menuChoice);
         break;
      
      case 'f':
         printf("Edited text: ");
         FixCapitalization(userString);
         PrintString(userString);
         PrintMenu(userString);
         scanf(" %c", &menuChoice);
         break;

      case 'r':
         printf("Edited text: ");
         ReplaceExclamation(userString);
         PrintString(userString);
         PrintMenu(userString);
         scanf(" %c", &menuChoice);
         break;

      case 's':
         printf("Edited text: ");
         ShortenSpace(userString);
         PrintString(userString);
         PrintMenu(userString);
         scanf(" %c", &menuChoice);
         break;

      default:
        printf("Error: Unknown option selected\n");
        PrintMenu(userString);
        scanf("%c", &menuChoice);
      break;
    }

   }
}