#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class ItemToPurchase
{
public:
    ItemToPurchase();
    ItemToPurchase(const string &defaultName, const int defaultPrice, const int defaultQuantity, const string &defaultDesc);
    void setName(string desiredName)const;
    string name()const;
    void setPrice(const int desiredPrice) const;
    int price() const;
    void setQuantity(const int desiredQuantity)const;
    int quantity();
    void setDescription(const &string desiredDesc) const;
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
