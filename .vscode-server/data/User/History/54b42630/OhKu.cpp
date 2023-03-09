#include "ItemToPurchase.h"
#include <iostream>
using namespace std;

ItemToPurchase::ItemToPurchase()
{
    name = "none";
    price = 0;
    quantity = 0;
    description = "none";
}
ItemToPurchase::ItemToPurchase(string defaultName, int defaultPrice, int defaultQuantity, string defaultDesc)
{
    name = defaultName;
    price = defaultPrice;
    quantity = defaultQuantity;
    description = defaultDesc;
}
void ItemToPurchase::setName(string desiredName){
    name = desiredName;
}
string ItemToPurchase::_name(){
    return name;
}
void ItemToPurchase::setPrice(int desiredPrice){
    price = desiredPrice;
}
int ItemToPurchase::_price(){
    return price;
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
string ItemToPurchase::_description(){
    return _description;
}
void ItemToPurchase::printItemCost(){
    cout << name << " " << quantity << "@" << price << " = " << quantity * price << endl;
}
void ItemToPurchase::printItemDescription(){
    cout << name << ": " << _description << endl;
}