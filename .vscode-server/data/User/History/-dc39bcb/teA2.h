#ifndef ItemToPurchase_H
#define ItemToPurchase_H

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
    string _description();
    void printItemCost();
    void printItemDescription();

private:
    string name;
    int price;
    int quantity;
    string _description;
};

#endif
