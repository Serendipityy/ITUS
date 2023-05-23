#pragma once
#include<iostream>
using namespace std;

class FoodOrderState;
class IFoodOrder {
public:
    virtual void setState(FoodOrderState* state) = 0;
    virtual FoodOrderState* getState() = 0;
    virtual void getOrder() = 0;
    virtual void checkOrder() = 0;
    virtual void cancelOrder() = 0;
    virtual void showStatus() = 0;
    /////////////////////////////////////
    virtual void markAsOutForDelivery() = 0;
    virtual void markAsDelivered() = 0;
};
class FoodOrder : public IFoodOrder {
private:
    FoodOrderState* currentState;
public:
    FoodOrder();
    ~FoodOrder();
    void setState(FoodOrderState* state);
    FoodOrderState* getState();
    void getOrder();
    void checkOrder();
    void cancelOrder();
    void showStatus();
    ///////////////////////////////////////
    void markAsOutForDelivery();
    void markAsDelivered();
};