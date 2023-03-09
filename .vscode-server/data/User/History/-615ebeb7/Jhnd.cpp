#include "ShoppingCart.h"
#include <iostream>
#include <vector>
using namespace std;

ShoppingCart::ShoppingCart()
{
    _customerName = "none";
    _currentDate = "January 1,2016";
}
ShoppingCart::ShoppingCart(const string &customerName, const string &currentDate)
{
    this->_customerName = customerName;
    this->_currentDate = currentDate;
}
string ShoppingCart::customerName()const
{
    return _customerName;
}
string ShoppingCart::date() const
{
    return _currentDate;
}
void ShoppingCart::addItem(const ItemToPurchase &item)const
{
    _cartItems.push_back(item);
}
void ShoppingCart::removeItem(const string &item) 
{
    bool found = false;
    for (unsigned int i = 0; i < _cartItems.size(); i++)
    {
        if (_cartItems[i].name() == item)
        {
            _cartItems.erase(_cartItems.begin() + i);
            found = true;
            break;
        }
    }
    if (found == false)
    {
        cout << "Item not found in cart. Nothing removed." << endl;
        cout << endl;
    }
}
void ShoppingCart::modifyItem(const ItemToPurchase &item)
{
    bool found = false;
    for (unsigned int i = 0; i < _cartItems.size(); i++)
    {
        if (_cartItems[i].name() == item.name())
        {
            if (item.description() != "none")
            {
                _cartItems[i].setDescription(item.description());
            }
            if (item.price() != 0)
            {
                _cartItems[i].setPrice(item.price());
            }
            if (item.name() != "none")
            {
                _cartItems[i].setName(item.name());
            }
            if (item.quantity() != 0)
            {
                _cartItems[i].setQuantity(item.quantity());
            }
            found = true;
            break;
        }
    }
    if (found == false)
    {
        cout << "Item not found in cart. Nothing modified." << endl;
        cout << endl;
    }
}
int ShoppingCart::numItemsInCart() const
{
    int numItems = 0;
    for (unsigned int i = 0; i < _cartItems.size(); i++)
    {
        numItems += _cartItems[i].quantity();
    }
    return numItems;
}
int ShoppingCart::costOfCart() const
{
    int cost = 0;
    for (unsigned int i = 0; i < _cartItems.size(); i++)
    {
        cost += (_cartItems[i].price() * _cartItems[i].quantity());
    }
    return cost;
}
void ShoppingCart::printTotal()const
{
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << "Number of Items: " << numItemsInCart() << endl;
    cout << endl;

    if (_cartItems.size() == 0)
    {
        cout << "SHOPPING CART IS EMPTY" << endl;
    }
    for (unsigned int i = 0; i < _cartItems.size(); i++)
    {
        _cartItems[i].printItemCost();
    }
    cout << endl;

    cout << "Total: " << "$" << costOfCart() << endl;
    cout << endl;
}
void ShoppingCart::printDescriptions() const
{
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << endl;

    cout << "Item Descriptions" << endl;
    for (unsigned int i = 0; i < _cartItems.size(); i++)
    {
        _cartItems[i].printItemDescription();
    }
}