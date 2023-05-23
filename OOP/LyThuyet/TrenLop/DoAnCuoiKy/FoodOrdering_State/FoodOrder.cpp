#include"FoodOrder.h"
#include"FoodOrderState.h"

FoodOrder::FoodOrder() {
    currentState = new WaitingOrderState(this);
}

void FoodOrder::setState(FoodOrderState* state) {
    currentState = state;
}

FoodOrderState* FoodOrder::getState() {
    return currentState;
}

void FoodOrder::getOrder() {
    currentState->getOrder();
}

void FoodOrder::checkOrder() {
    currentState->checkOrder();
}

void FoodOrder::cancelOrder() {
    currentState->cancelOrder();
}

void FoodOrder::showStatus() {
    currentState->showStatus();
}

FoodOrder::~FoodOrder() {
    delete currentState;
}

//////////////////////////////////////
void FoodOrder::markAsOutForDelivery() {
    currentState->markAsOutForDelivery();
}

void FoodOrder::markAsDelivered() {
    currentState->markAsDelivered();
}
