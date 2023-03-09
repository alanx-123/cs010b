#include <iostream>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

int main()
{
    ItemToPurchase testItem("Test",1,1,"This is a test bench.");

    testItem.setName("Test Bench");
    testItem.setDescription("This is a test bench x2.");
    testItem.setPrice(4);
    testItem.setQuantity(5);

    cout << testItem.name() << endl;
    cout << testItem.quantity() << endl;
    cout << testItem.price() << endl;
    cout << testItem.description() << endl;

    testItem.printItemCost();
    testItem.printItemDescription();

    cout << "ItemToPurchase test bench completed." << endl;
    cout << endl;
    cout << "-----------------------------------" << endl;

    //ShoppingCart testCart;



    return 0;
}

/*
ItemToPurchase();
ItemToPurchase(string defaultName, int defaultPrice, int defaultQuantity, string defaultDesc);
void setName(string desiredName);
string name();
void setPrice(int desiredPrice);
int price();
void setQuantity(int desiredQuantity);
int quantity();
void setDescription(string desiredDesc);
string description();
void printItemCost();
void printItemDescription();
*/