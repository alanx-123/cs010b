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


    private:
        string name;
        int price;
        int quantity;
};









#endif






