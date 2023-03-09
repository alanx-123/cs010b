#include "ShoppingCart.h"
#include <iostream>
#include <vector>
using namespace std;

ShoppingCart::ShoppingCart(){
    _customerName = "none";
    _currentDate = "January 1,2016";
}
ShoppingCart::ShoppingCart(string customerName, string currentDate){
    this ->_customerName = customerName;
    this -> _currentDate = currentDate;
}
string ShoppingCart::customerName(){
    return _customerName;
}
string ShoppingCart::date(){
    return _currentDate;
}
void ShoppingCart::addItem(ItemToPurchase item){
    _cartItems.push_back(item);
}
void ShoppingCart::removeItem(string item){
    bool found = false;
    for (unsigned int i = 0; i < _cartItems.size(); i++){
        if (_cartItems[i] == item){
            _cartItems.erase(_cartItems.begin() + i);
            found = true;
            break;
        }
    }
    if (found == false){
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}
void ShoppingCart::modifyItem(ItemToPurchase item){
    bool found = false;
    for (int i = 0; i < _cartItems.size(); i++){
        if (_cartItems[i] == item){
            if(_cartItems[i].description() != "none"){
                _cartItems[i].setDescription(item.description());
            }
            if(_cartItems[i].price() != 0){
                _cartItems[i].setDescription(item.price());
            }
            if(_cartItems[i].name() != "none"){
                _cartItems[i].setName(item.name());
            }
            if(_cartItems[i].quantity() != 0){
                _cartItems[i].setQuantity(item.quantity());
            }
        }
    }
    if (found == false){
        cout << "Item not found in cart. Nothing modified." << endl;
    }
}
int ShoppingCart::numItemsInCart(){
    int numItems = 0;
    for (int i = 0; i < _cartItems.size(); i++){
        numItems += _cartItems[i].quantity();
    }
    return numItems;
} 
int ShoppingCart::costOfCart(){
    int cost = 0;
    for (int i =0; i < _cartItems.size(); i++){
        cost += _cartItems[i].price();
    }
    return cost;
}
void ShoppingCart::printTotal(){
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << "Number of Items: " << numItemsInCart() << endl;
    cout << endl;
    
    for (int i = 0; i < _cartItems.size(); i++){
        _cartItems[i].printItemCost();
    }
    cout << endl;

    cout << "Total: " << costOfCart << endl;
}
void ShoppingCart::printDescriptions(){
    cout << _customerName << "'s Shopping Cart - " << _currentDate << endl;
    cout << endl;

    cout << "Item Descriptions" << endl;
    for (int i = 0; i < _cartItems.size(); i++){
        cout << 
    }
}