#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class ItemToPurchase
{
public:
    ItemToPurchase();
    ItemToPurchase(string defaultName, int defaultPrice, int defaultQuantity, string defaultDesc);
    void setName(string desiredName);
    string name();
    void setPrice(int desiredPrice);
    int price();
    void setQuantity(int desiredQuantity);
    int quantity();
    void setDescription(string desiredDesc);
    void printItemCost();
    void printItemDescription();

private:
    string _name;
    int _price;
    int _quantity;
    string _description;
};

#endif
