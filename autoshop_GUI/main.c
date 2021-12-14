/*
* Author: Samuel Wasko
* Date: Sun Sep 19, 2021
* Description: Lab 4 Davy's scanf input and printf output service center
*/

#include <stdio.h>
#include <string.h>



int main(void) {

   const int MAX_WORD_LENGTH = 40;
   char serviceWord1[MAX_WORD_LENGTH + 1];
   char serviceWord2[MAX_WORD_LENGTH + 1];
   char serviceWord2_1[MAX_WORD_LENGTH + 1];
   char serviceWord2_2[MAX_WORD_LENGTH + 1];
   int price1,price2,totalPrice;

/* Intro GUI scans in services */
   printf("Davy's auto shop services\nOil change -- $35\nTire rotation -- $19\nCar wash -- $7\nCar wax -- $12\n");
   printf("\nSelect first service:\n");
   scanf("%40s %40s", serviceWord1, serviceWord2);
   printf("\nSelect second service:\n");
   scanf("%40s %40s", serviceWord2_1, serviceWord2_2);

/* Invoice prints out selected services with prices and a total */
   printf("Davy's auto shop invoice\n\n");
   
   /* conditionals for service 1 */

if ((strcmp(serviceWord1, "Oil") == 0) && (strcmp(serviceWord2,"change") == 0)) {
   printf("Service 1: Oil change, $35\n");
   price1 = 35;
}  else if ((strcmp(serviceWord1, "Tire") == 0) && (strcmp(serviceWord2,"rotation") == 0)) {
   printf("Service 1: Tire rotation, $19\n");
   price1 = 19;
}  else if ((strcmp(serviceWord1, "Car") == 0) && (strcmp(serviceWord2,"wash") == 0)) {
   printf("Service 1: Car wash, $7\n");
   price1 = 7;
}  else if ((strcmp(serviceWord1, "Car") == 0) && (strcmp(serviceWord2,"wax") == 0)) {
   printf("Service 1: Car wax, $12\n");
   price1 = 12;
}  else if ((strcmp(serviceWord1, "-") == 0) && (strcmp(serviceWord2,"-") == 0)) {
   printf("Service 1: No service\n");
   price1 = 0;
}  else {
   printf("The requested service is not recognized\n");
}
   /* conditionals for service 2 */

if ((strcmp(serviceWord2_1, "Oil") == 0) && (strcmp(serviceWord2_2,"change") == 0)) {
   printf("Service 2: Oil change, $35\n");
   price2 = 35;
}  else if ((strcmp(serviceWord2_1, "Tire") == 0) && (strcmp(serviceWord2_2,"rotation") == 0)) {
   printf("Service 2: Tire rotation, $19\n");
   price2 = 19;
}  else if ((strcmp(serviceWord2_1, "Car") == 0) && (strcmp(serviceWord2_2,"wash") == 0)) {
   printf("Service 2: Car wash, $7\n");
   price2 = 7;
}  else if ((strcmp(serviceWord2_1, "Car") == 0) && (strcmp(serviceWord2_2,"wax") == 0)) {
   printf("Service 2: Car wax, $12\n");
   price2 = 12;
}  else if ((strcmp(serviceWord2_1, "-") == 0) && (strcmp(serviceWord2_2,"-") == 0)) {
   printf("Service 2: No service\n");
   price2 = 0;
}  else {
   printf("The requested service is not recognized\n");
}
/* total price arithmetic and printout */

   totalPrice = price1 + price2;
   printf("\nTotal: $%d\n", totalPrice);
   
   return 0;
}