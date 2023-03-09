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
string ItemToPurchase::name(){
    return name;
}
void ItemToPurchase::setPrice(int desiredPrice){
    price = desiredPrice;
}
int ItemToPurchase::price(){
    return price;
}
void ItemToPurchase::setQuantity(int desiredQuantity){
    quantity = desiredQuantity;
}
int ItemToPurchase::quantity(){
    return quantity;
}
void ItemToPurchase::setDescription(string desiredDesc){
    description = desiredDesc;
}
string ItemToPurchase::description(){
    return description;
}
void ItemToPurchase::printItemCost(){
    cout << name << " " << quantity << "@" << price << " = " << quantity * price << endl;
}
void ItemToPurchase::printItemDescription(){
    cout << name << ": " << description << endl;
}