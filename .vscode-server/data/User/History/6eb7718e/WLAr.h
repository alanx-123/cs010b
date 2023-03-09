#ifndef CART_H
#define CART_H

#include "ItemToPurchase.h"
#include <vector>

using namespace std;

class ShoppingCart
{
public:
    ShoppingCart();
    ShoppingCart(const string &_customerName, const string & _currentDate);
    string customerName();
    string date();
    void addItem(ItemToPurchase item);
    void removeItem(string item); 
    void modifyItem(ItemToPurchase item);
    int numItemsInCart(); 
    int costOfCart();
    void printTotal();
    void printDescriptions();

private:
    string _customerName;
    string _currentDate;
    vector<ItemToPurchase> _cartItems;
};

#endif