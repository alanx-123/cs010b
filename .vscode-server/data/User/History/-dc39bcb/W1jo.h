#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class ItemToPurchase
{
public:
    ItemToPurchase();
    ItemToPurchase(const string &defaultName, int defaultPrice, int defaultQuantity, const string &defaultDesc);
    void setName(const string &desiredName);
    string name()const;
    void setPrice(int desiredPrice);
    int price() const;
    void setQuantity(int desiredQuantity);
    int quantity() const;
    void setDescription(const string &desiredDesc);
    void printItemCost() const;
    void printItemDescription() const;
    string description() const;

private:
    string _name;
    int _price;
    int _quantity;
    string _description;
};

#endif
