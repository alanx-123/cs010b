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
    
}
string ItemToPurchase::name();
void ItemToPurchase::setPrice(int desiredPrice);
int ItemToPurchase::price();
void ItemToPurchase::setQuantity(int desiredQuantity);
int ItemToPurchase::quantity();
void ItemToPurchase::setDescription(string desiredDesc);
string ItemToPurchase::description();
void ItemToPurchase::printItemCost();
void ItemToPurchase::printItemDescription();