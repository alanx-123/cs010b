#include "ItemToPurchase.h"
#include <iostream>
using namespace std;

ItemToPurchase::ItemToPurchase()
{
    name = "none";
    price = 0;
    quantity = 0;
    _description = "none";
}
ItemToPurchase::ItemToPurchase(string defaultName, int defaultPrice, int defaultQuantity, string defaultDesc)
{
    name = defaultName;
    price = defaultPrice;
    quantity = defaultQuantity;
    _description = defaultDesc;
}
void ItemToPurchase::setName(string desiredName){
    _name = desiredName;
}
string ItemToPurchase::name(){
    return _name;
}
void ItemToPurchase::setPrice(int desiredPrice){
    price = desiredPrice;
}
int ItemToPurchase::price(){
    return _price;
}
void ItemToPurchase::setQuantity(int desiredQuantity){
    quantity = desiredQuantity;
}
int ItemToPurchase::_quantity(){
    return quantity;
}
void ItemToPurchase::setDescription(string desiredDesc){
    _description = desiredDesc;
}
void ItemToPurchase::printItemCost(){
    cout << name << " " << quantity << " @ " << price << " = " << "$" << quantity * price << endl;
}
void ItemToPurchase::printItemDescription(){
    cout << name << ": " << _description << endl;
}