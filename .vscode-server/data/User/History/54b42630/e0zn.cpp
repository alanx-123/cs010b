#include "ItemToPurchase.h"
#include <iostream>
using namespace std;

ItemToPurchase::ItemToPurchase()
{
    _name = "none";
    _price = 0;
    _quantity = 0;
    _description = "none";
}
ItemToPurchase::ItemToPurchase(const string &defaultName, const int defaultPrice, const int defaultQuantity, const string &defaultDesc) 
{
    _name = defaultName;
    _price = defaultPrice;
    _quantity = defaultQuantity;
    _description = defaultDesc;
}
void ItemToPurchase::setName(const string &desiredName) const {
    _name = desiredName;
}
string ItemToPurchase::name(){
    return _name;
}
void ItemToPurchase::setPrice(int desiredPrice){
    _price = desiredPrice;
}
int ItemToPurchase::price(){
    return _price;
}
void ItemToPurchase::setQuantity( int desiredQuantity){
    _quantity = desiredQuantity;
}
int ItemToPurchase::quantity(){
    return _quantity;
}
void ItemToPurchase::setDescription(const string &desiredDesc){
    _description = desiredDesc;
}
void ItemToPurchase::printItemCost()const{
    cout << _name << " " << _quantity << " @ " << "$" <<  _price << " = " << "$" << _quantity * _price << endl;
}
void ItemToPurchase::printItemDescription() const{
    cout << _name << ": " << _description << endl;
}
string ItemToPurchase::description()const{
    return _description;
}