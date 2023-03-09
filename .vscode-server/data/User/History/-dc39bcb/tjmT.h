#ifndef ItemToPurchase_H
#define ItemToPurchase_H

using namespace std;

class ItemToPurchase{
    public:
        ItemToPurchase();
        ItemToPurchase(string defaultName, int defaultPrice, int defaultQuantity);
        void SetName();
        string name();
        void setPrice();
        int price();  
        void setQuantity();
        int quantity();
        void setDescription();
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






