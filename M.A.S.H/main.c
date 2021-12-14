/* 
 * File: main.c
 * Author: Samuel Wasko
 * Date: 31 Oct 2021
 * Description: Main program file for the M.A.S.H. game. Contains game database, Game UI,
 * And the action of freeing the dynamic memory that the game takes up when a round is complete.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include "DataNode.h"

char userName;
DataNode * database[6];

enum {homeList, maleSpouse, femaleSpouse, occupationList, transportationList, hometownList};

void menu(void) {
   /* Data Values & Build Database */
   char* HOME_LIST[5] = {"mansion", "leased apartment", "shack", "dark alley", "cave"};
   database[homeList] = BuildDataList(HOME_LIST, 5);

   char* FEMALE_SPOUSE_LIST[5] = {"Judy", "Norah", "Zoey", "Robin", "Juli"};
   database[maleSpouse] = BuildDataList(FEMALE_SPOUSE_LIST, 5);

   char* MALE_SPOUSE_LIST[5] = {"John", "Jacob", "Michael", "Ted", "Tony"};
   database[femaleSpouse] = BuildDataList(MALE_SPOUSE_LIST, 5);
   
   char* OCCUPATION_LIST[5] = {"Teacher", "Architect", "Lawyer", "Unemployed Loser", "Librarian"};
   database[occupationList] = BuildDataList(OCCUPATION_LIST, 5);

   char* TRANSPORTATION_LIST[5] = {"ride a train", "drive your car", "fly your plane", "pedal your moped", "huff it on foot"};
   database[transportationList] = BuildDataList(TRANSPORTATION_LIST, 5);

   char* HOMETOWN_LIST[5] = {"Maui Islands", "Denver Mountains", "Boise Valley", "Orlando Burbs", "Tokyo Highrises"};
   database[hometownList] = BuildDataList(HOMETOWN_LIST, 5);


   /*UI with DataList printouts*/
   printf("--------------------- Future Possibilities Database -----------------------\n");
   printf("Home List: ");
   PrintDataList(database[homeList]);
   printf("Female Spouse List: ");
   PrintDataList(database[femaleSpouse]);
   printf("Male Spouse List: ");
   PrintDataList(database[maleSpouse]);
   printf("Occupation List: ");
   PrintDataList(database[occupationList]);
   printf("Transportation list: ");
   PrintDataList(database[transportationList]);
   printf("Hometown List: ");
   PrintDataList(database[hometownList]);
   printf("----------------------------------------------------------------------------");
   printf("\n\nPlease enter your name: ");
   scanf("%s", &userName);
   printf("\n\n");
}

void MASH(void) {
int years = -1;
printf("You will marry ");
//random female or male spouse choice
if (rand() % 2 == 0) {
PrintDataNode(GetRandomDataNode(database[femaleSpouse]));
}
else {
PrintDataNode(GetRandomDataNode(database[maleSpouse]));
}
printf(" and live in a ");
PrintDataNode(GetRandomDataNode(database[homeList]));
printf(".\n");
years = rand() % 90;
printf("After %d years of marriage, you will finally get your dream job of being a ", years);
PrintDataNode(GetRandomDataNode(database[occupationList]));
printf(".\n");
printf("Your family will move to a ");
PrintDataNode(GetRandomDataNode(database[homeList]));
printf(" in The ");
PrintDataNode(GetRandomDataNode(database[hometownList]));
printf(" where you will ");
PrintDataNode(GetRandomDataNode(database[transportationList]));
printf(" to work each day.");
printf("\n");
}

void destroy(void) {
DestroyDataList(database[homeList]);
DestroyDataList(database[femaleSpouse]);
DestroyDataList(database[maleSpouse]);
DestroyDataList(database[occupationList]);
DestroyDataList(database[transportationList]);
DestroyDataList(database[hometownList]);
}

int main(void) {
srand(time(0));
printf("\n\n");
menu();
printf("Welcome %s, this is your future...\n", &userName);
MASH();
printf("\n");
//destroy data list (free memory!)
destroy();

   return 0;
}