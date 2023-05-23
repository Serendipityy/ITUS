#pragma once
#include <iostream>
using namespace std;

class IFoodOrder;

class FoodOrderState {
public:
    virtual void getOrder() = 0;
    virtual void checkOrder() = 0;
    virtual void cancelOrder() = 0;
    virtual void showStatus() = 0;
    //////////////////////////////////////
    virtual void markAsOutForDelivery() = 0;
    virtual void markAsDelivered() = 0;
};

class WaitingOrderState : public FoodOrderState {
private:
    IFoodOrder* order;
public:
    WaitingOrderState(IFoodOrder* _order);
    void getOrder();
    void checkOrder();
    void cancelOrder();
    void showStatus();
    ///////////////////////////////////////
    void markAsOutForDelivery();
    void markAsDelivered();
};

class OrderPlacedStatus : public FoodOrderState {
private:
    IFoodOrder* order;
public:
    OrderPlacedStatus(IFoodOrder* _order);
    void getOrder();
    void checkOrder();
    void cancelOrder();
    void showStatus();
    ///////////////////////////////////////
    void markAsOutForDelivery();
    void markAsDelivered();

};

class FoodPreparationState : public FoodOrderState {
private:
    IFoodOrder* order;
public:
    FoodPreparationState(IFoodOrder* _order);
    void getOrder();
    void checkOrder();
    void cancelOrder();
    void showStatus();
    ///////////////////////////////////////
    void markAsOutForDelivery();
    void markAsDelivered();
};


class OutForDeliveryState : public FoodOrderState {
private:
    IFoodOrder* order;
public:
    OutForDeliveryState(IFoodOrder* _order);
    void getOrder();
    void checkOrder();
    void cancelOrder();
    void showStatus();
    ///////////////////////////////////////
    void markAsOutForDelivery();
    void markAsDelivered();
};

class DeliveredState : public FoodOrderState {
private:
    IFoodOrder* order;
public:
    DeliveredState(IFoodOrder* _order);
    void getOrder();
    void checkOrder();
    void cancelOrder();
    void showStatus();
    ///////////////////////////////////////
    void markAsOutForDelivery();
    void markAsDelivered();
};