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
    string customerName() const;
    string date() const;
    void addItem(const ItemToPurchase &item);
    void removeItem(const string &item); 
    void modifyItem(const ItemToPurchase &item);
    int numItemsInCart() const; 
    int costOfCart() const;
    void printTotal() const;
    void printDescriptions() const;

private:
    string _customerName;
    string _currentDate;
    vector<ItemToPurchase> _cartItems;
};

#endif