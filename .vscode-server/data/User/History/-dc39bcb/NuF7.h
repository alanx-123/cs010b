#ifndef ItemToPurchase_H
#define ItemToPurchase_H

using namespace std;

class ItemToPurchase{
    public:
        ItemToPurchase();
        ItemToPurchase(name,price,quantity);
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






