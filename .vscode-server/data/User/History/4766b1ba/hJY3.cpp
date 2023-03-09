#include <iostream>
using namespace std;

#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void printMenu(ShoppingCart &cart);

int main()
{
    string customerName;
    string currentDate;

    cout << "Enter customer's name: ";
    getline(cin, customerName);
    cout << endl;

    cout << "Enter today's date: ";
    getline(cin, currentDate);
    cout << endl;

    ShoppingCart cart(customerName, currentDate);
    cout << endl;

    cout << "Customer name: " << customerName << endl;
    cout << "Today's date: " << currentDate << endl;
    cout << endl;

    printMenu(cart);
    cout << endl;

    return 0;
}

void printMenu(ShoppingCart &cart)
{
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;

    cout << endl;

    cout << "Choose an option: ";

    char choice;

    cin >> choice;
    cin.ignore();

    string itemName;
    string itemDescription;
    int itemPrice;
    int itemQuantity;

    cout << endl;

    if (choice != 'q' || choice != 'a' || choice != 'd' || choice != 'c' || choice != 'i' || choice != 'o')
    {
        while (choice != 'q' || choice != 'a' || choice != 'd' || choice != 'c' || choice != 'i' || choice != 'o')
        {
            cout << "Choose an option: ";
            cin >> choice;
        }
    }
    if (choice == 'q')
    {
        cout << endl;
        exit(1);
    }
    if (choice == 'a')
    {
        cout << endl;
        cout << "ADD ITEM TO CART" << endl;
        cout << "Enter the item name: " << endl;
        getline(cin, itemName);

        cout << "Enter the item description: " << endl;
        getline(cin, itemDescription);

        cout << "Enter the item price: " << endl;
        cin >> itemPrice;
        cout << "Enter the item quantity: " << endl;
        cin >> itemQuantity;
        cout << endl;

        ItemToPurchase addingItem(itemName, itemDescription, itemPrice, itemQuantity);
        cart.addItem(addingItem);
    }
    else if (choice == 'd')
    {
        cout << endl;
        cout << "REMOVE ITEM FROM CART" << endl;
        cout << "Enter name of item to remove: " << endl;
        cin >> itemName;

        cart.removeItem(itemName);
    }
    else if (choice == 'c')
    {
        cout << endl;
        cout << "CHANGE ITEM QUANTITY" << endl;
        cout << "Enter the item name: " << endl;
        cin >> itemName;
        cout << "Enter the new quantity: " << endl;
        cin >> itemQuantity;
        cout << endl;

        ItemToPurchase itemToModify(itemName, "none", 0, itemQuantity);
        printMenu(cart);
    }
    else if (choice == 'i')
    {
        cout << endl;
        cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
        cart.printDescriptions();
    }
    else if (choice == 'o')
    {
        cout << endl;
        cout << "OUTPUT SHOPPING CART" << endl;
        cart.printTotal();
    }
    
}