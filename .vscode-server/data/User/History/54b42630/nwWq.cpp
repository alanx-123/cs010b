#include "ItemToPurchase.h"
using namespace std;

ItemToPurchase::ItemToPurchase()
{
    name = "none";
    price = 0;
    quantity = 0;
    description = "none";
}
ItemToPurchase::ItemToPurchase(string defaultName, int defaultPrice, int defaultQuantity)
{
    name = defaultName;
    price = defaultPrice;
    quantity = defaultQuantity;
}
void ItemToPurchase::setName(string desiredName){
    name = desiredName;
}
string ItemToPurchase::name();
void ItemToPurchase::setPrice(int desiredPrice){
    price = desiredPrice;
}
int ItemToPurchase::price();
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
    cout << name <<
}
void ItemToPurchase::printItemDescription();