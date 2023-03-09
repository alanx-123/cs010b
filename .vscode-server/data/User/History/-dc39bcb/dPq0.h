#ifndef iTEMtOpURCHASE_H
#define ITEMTOPURCHASE_H
#include <string>

using namespace std;

class ItemToPurchase
{
public:
    ItemToPurchase();
    ItemToPurchase(string defaultName, int defaultPrice, int defaultQuantity, string defaultDesc);
    void setName(string desiredName);
    string _name();
    void setPrice(int desiredPrice);
    int _price();
    void setQuantity(int desiredQuantity);
    int _quantity();
    void setDescription(string desiredDesc);
    void printItemCost();
    void printItemDescription();

private:
    string name;
    int price;
    int quantity;
    string _description;
};

#endif
