#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#define MAX_ITEM_NAME_SIZE 80

/* Define itemtopurchase struct */
struct itemtopurchase {
    char itemName[MAX_ITEM_NAME_SIZE];
    char itemDescription[MAX_ITEM_NAME_SIZE];
    int itemPrice;
    int itemQuantity;
};

/* Define ItemToPurchase type */
typedef struct itemtopurchase ItemToPurchase;

/* MakeItemBlank: Initialize the fields in the specified ItemToPurchase struct
 * item - Pointer to ItemToPurchase object
 * return - 0 on success, -1 on error
 */
int MakeItemBlank(ItemToPurchase * itemPtr);

/*
 * PrintItemCost - Display item cost by printing to stdout
 * item - ItemToPurchase object to be displayed
 */
void PrintItemCost(ItemToPurchase item);

/*
 * PrintItemDecription: display item name and description
 * item - ItemToPurchase object to be displayed
 */
void PrintItemDescription(ItemToPurchase item);

#endif