#include "ItemToPurchase.h"
using namespace std;

ItemToPurchase::ItemToPurchase(){
    name = "none";
    price = 0;
    quantity = 0;
}
ItemToPurchase::ItemToPurchase(string defaultName, int defaultPrice, int defaultQuantity){
    name = defaultName;
    price = defaultPrice;
    quantity = defaultQuantity;
}

