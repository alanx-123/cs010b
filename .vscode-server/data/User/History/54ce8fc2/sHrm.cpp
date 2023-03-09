#include "ShoppingCart.h"
#include <iostream>
#include <vector>
using namespace std;

ShoppingCart();
ShoppingCart(string customerName, string currentDate){
    this ->_customerName = customerName;
    this -> _currentDate = currentDate;
}
string ShoppingCart::customerName(){
    return "IMPLEMENT ME";
}
string ShoppingCart::date(){
    return "IMPLEMENT ME";
}
void ShoppingCart::addItem(ItemToPurchase item){
    cout << "IMPLEMENT ME";
}
void ShoppingCart::removeItem(string item){
    cout << "IMPLEMENT ME";
} // we need to convert item to ItemToPurchase
void ShoppingCart::modifyItem(ItemToPurchase item){
    cout << "IMPLEMENT ME";
}
int ShoppingCart::numItemsInCart(){
    cout << "IMPLEMENT ME";
    return -1;
} // we can implement using count after iterating thru vector
int ShoppingCart::costOfCart(){
    cout << "IMPLEMENT ME";
    return -1;
}
void ShoppingCart::printTotal(){
    cout << "IMPLEMENT ME";
}
void ShoppingCart::printDescriptions(){
    cout << "IMPLEMENT ME";
}