#ifndef ItemToPurchase_H
#define ItemToPurchase_H

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
    string description();
    void printItemCost();
    void printItemDescription();

private:
    string name;
    int price;
    int quantity;
    string description;
};

#endif
