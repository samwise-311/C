/*
* Author: Samuel Wasko
* Date:Tue 12 Oct 2021
* Description:
*/

#include<stdio.h>
#include<string.h>

#include "ShoppingCart.h"

/*
 * BufferPurge: Remove all remaining characters from the input buffer.
 */
void BufferPurge(void) {
   char c = getchar();
   while(c != '\n' && c != EOF) {
      c = getchar();
   }
}

char printMenu() {
//Declare required variables.
char choice = " ";
char ignore = " ";
//Display the menu of choices.
printf("MENU\n");
printf("a - Add item to cart\n");
printf("r - Remove item from cart\n");
printf("c - Change item quantity\n");
printf("i - Output items' descriptions\n");
printf("o - Output shopping cart\n");
printf("q - Quit\n");
//Prompt the user to enter the required choice.
printf("\nChoose an option: ");
scanf("%c", &choice);
//Store the next line character which will come when
//a character is prompted.
scanf("%c", &ignore);
//Return the choice value.
return choice;
}

int main(void) {
   /* Declare variables */
   int rc = 0;
   ItemToPurchase item1, item2;
   //int totalCost = 0;
   ShoppingCart userCart;
char customerName;
char currentDate;

   /* Initialize items */
   rc = MakeItemBlank(&item1);
   if (rc < 0) {
      printf("Error: unable to initialize item1\n");
      return 1;
   }

   rc = MakeItemBlank(&item2);
   if (rc < 0) {
      printf("Error: unable to initialize item2\n");
      return 1;
   }



userCart.cartSize = 0;

customerName = "none";
currentDate = customerName;

/* setup user profile info */
printf("Enter Customer's Name:\n");
fgets()
printf("Enter Today's Date:\n");
 scanf("%s", currentDate);
printf("\nCustomer Name: %s\n", customerName);
printf("Today's Date: %s\n", currentDate);

//PrintMenu(userCart);

//   /* Setup first item */
//    printf("Item 1\n");
//    printf("Enter the item name: ");
//    scanf("%79[^\n]s", item1.itemName);
//    BufferPurge();
//    printf("Enter the item description: ");
//    scanf("%79[^\n]s", item1.itemDescription);
//    BufferPurge();
//    printf("Enter the item price: ");
//    /* read price and validate user response */
//    while (scanf("%d", &item1.itemPrice) <1) {
//       printf("Please enter an integer value\n");
//       BufferPurge();
//   }
//    BufferPurge();
//    printf("Enter the item quantity: ");
//    while (scanf("%d", &item1.itemQuantity) <1) {
//       printf("Please enter an integer value\n");
//       BufferPurge();
//   }
//    BufferPurge();

//    /* Setup second item */
//    printf("\nItem 2\n");
//    printf("Enter the item name: ");
//    scanf("%79[^\n]s", item2.itemName);
//    BufferPurge();
//    printf("Enter the item description: ");
//    scanf("%79[^\n]s", item2.itemDescription);
//    BufferPurge();
//    printf("Enter the item price: ");
//    while (scanf("%d", &item2.itemPrice) <1) {
//       printf("Please enter an integer value\n");
//       BufferPurge();
//   }
//    BufferPurge();
//    printf("Enter the item quantity: ");
//    while (scanf("%d", &item1.itemQuantity) <1) {
//       printf("Please enter an integer value\n");
//       BufferPurge();
//   }
//    BufferPurge();


//    /* Calculate total cost */
//    totalCost += item1.itemQuantity * item1.itemPrice;
//    totalCost += item2.itemQuantity * item2.itemPrice;

//    /* Display the items */
//    printf("\n\nTOTAL COST\n");
//    PrintItemCost(item1);
//    PrintItemCost(item2);
//    printf("Total: %d\n",totalCost);



   return 0;
}