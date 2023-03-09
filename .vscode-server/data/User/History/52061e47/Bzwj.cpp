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

    ShoppingCart testCart("Gordon Ramsay", "January 30, 2023");

    cout << testCart.customerName() << endl;
    cout << testCart.date() << endl;

    ItemToPurchase addingItem1("Idiot Sandwich", 3 , 5, "Gordon Ramsay is a world famous chef");
    ItemToPurchase addingItem2("Apple", 3 , 5 , "I love apples");
    ItemToPurchase addingItem3("Orange", 2, 1 , "I dislike oranges");
    ItemToPurchase modifyTest("Apple", 1 , 2 , "I love apple pie!");
    ItemToPurchase fakeItem("Apple Pie", 1 , 2 , "I love apple pie!");



    testCart.addItem(addingItem1);
    testCart.addItem(addingItem2);
    testCart.addItem(addingItem3);
    testCart.removeItem(fakeItem);
    testCart.modify(fakeItem);

    testCart.removeItem("Orange");
    testCart.modifyItem(modifyTest);

    testCart.printTotal();
    testCart.printDescriptions();




    return 0;
}
/*
ShoppingCart();
    ShoppingCart(string _customerName, string _currentDate);
    string customerName();
    string date();
    void addItem(ItemToPurchase item);
    void removeItem(string item); //we need to convert item to ItemToPurchase
    void modifyItem(ItemToPurchase item);
    int numItemsInCart(); // we can implement using count after iterating thru vector
    int costOfCart();
    void printTotal();
    void printDescriptions();
/*/

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