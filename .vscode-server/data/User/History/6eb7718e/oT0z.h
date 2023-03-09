#ifndef ShoppingCart_H
#define ShoppingCart_H

using namespace std;

class ShoppingCart
{
public:
    ShoppingCart();
    ShoppingCart(string _customerName, string _currentDate);
    string customerName();
    string date();
    void addItem(ItemToPurchase item);
    void removeItem(string item)

private:
    string _customerName;
    string _currentDate;
    vector<ItemToPurchase> _cartItems;
}

#endif