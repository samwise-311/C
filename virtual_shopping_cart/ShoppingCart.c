#include<stdio.h>
#include<string.h>

#include "ShoppingCart.h"

ShoppingCart AddItem(ItemToPurchase itemToAdd,
ShoppingCart sh_cart)
{
sh_cart.cartItems[sh_cart.cartSize] = itemToAdd;
sh_cart.cartSize++;
//Return the shopping cart structure variable.
return sh_cart;
}

