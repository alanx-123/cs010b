#ifndef ShoppingCart_H
#define ShoppingCart_H
#include "ItemToPurchase.h"
#include <vector>

using namespace std;

class ShoppingCart
{
public:
    ShoppingCart();
    ShoppingCart(string _customerName, string _currentDate);
    string customerName();
    string date();
    void addItem(ItemToPurchase item);
    void removeItem(string item); //we need to convert item to ItemToPurchase
    void modifyItem(ItemToPurchase item);
    int numItemsInCart(); // we can implement using count after iterating thru vector
    int costOfCart();
    void printTotal();
    void printDescriptions();

private:
    string _customerName;
    string _currentDate;
    vector<ItemToPurchase> _cartItems;
};

#endif