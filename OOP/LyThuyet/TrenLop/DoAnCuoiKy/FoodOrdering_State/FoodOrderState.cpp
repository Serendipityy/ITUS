#include"FoodOrder.h"
#include"FoodOrderState.h"

WaitingOrderState::WaitingOrderState(IFoodOrder* _order) {
    order = _order;
}

void WaitingOrderState::getOrder() {
    cout << "Order received, it will be placed soon." << endl;
    OrderPlacedStatus* orderPlacedStatus = new OrderPlacedStatus(order);
    order->setState(orderPlacedStatus);
    delete this;
}

void WaitingOrderState::checkOrder() {
    cout << "Your order is still being processed." << endl;
}

void WaitingOrderState::cancelOrder() {
    cout << "Order cancelled." << endl;
    delete order->getState();
    order->setState(nullptr);
    delete this;
}

void WaitingOrderState::showStatus() {
    cout << "Waiting for order to be placed." << endl;
}

//////////////////////////////////////////
void WaitingOrderState::markAsOutForDelivery() {
    cout << "Can't mark as Out For Delivery yet." << endl;
}

void WaitingOrderState::markAsDelivered() {
    cout << "Can't mark as Delivered yet." << endl;
}



OrderPlacedStatus::OrderPlacedStatus(IFoodOrder* _order) {
    order = _order;
}

void OrderPlacedStatus::getOrder() {
    cout << "Order is already placed, please wait for it to be prepared." << endl;
}

void OrderPlacedStatus::checkOrder() {
    FoodPreparationState* foodPreparationState = new FoodPreparationState(order);
    order->setState(foodPreparationState);
    delete this;
}

void OrderPlacedStatus::cancelOrder() {
    cout << "Order cancelled." << endl;
    delete order->getState();
    order->setState(nullptr);
    delete this;
}

void OrderPlacedStatus::showStatus() {
    cout << "Order placed, waiting for it to be prepared." << endl;
}
//////////////////////////////////////////
void WaitingOrderState::markAsOutForDelivery() {
    cout << "Can't mark as Out For Delivery yet." << endl;
}

void WaitingOrderState::markAsDelivered() {
    cout << "Can't mark as Delivered yet." << endl;
}


FoodPreparationState::FoodPreparationState(IFoodOrder* _order) {
    order = _order;
}

void FoodPreparationState::getOrder() {
    cout << "Order is being prepared, please wait." << endl;
}

void FoodPreparationState::checkOrder() {
    //OutForDeliveryState* outForDeliveryState = new OutForDeliveryState(order);
    //order->setState(outForDeliveryState);
    //delete this;
    cout << "Order is being checked, please wait." << endl;
}

void FoodPreparationState::cancelOrder() {
    cout << "Can't cancel after placing." << endl;
}

void FoodPreparationState::showStatus() {
    cout << "Order is being prepared, please wait." << endl;
}

////////////////////////////////////////////
void FoodPreparationState::markAsOutForDelivery() {
    OutForDeliveryState* outForDeliveryState = new OutForDeliveryState(order);
    order->setState(outForDeliveryState);
    delete this;
}

void FoodPreparationState::markAsDelivered() {
    cout << "Can't mark as delivered before out for delivery." << endl;
}


OutForDeliveryState::OutForDeliveryState(IFoodOrder* _order) {
    order = _order;
}

void OutForDeliveryState::getOrder() {
    cout << "Order is out for delivery, please wait." << endl;
}

void OutForDeliveryState::checkOrder() {
    DeliveredState* deliveredState = new DeliveredState(order);
    order->setState(deliveredState);
    delete this;
}

void OutForDeliveryState::cancelOrder() {
    cout << "Can't cancel after placing." << endl;
}

void OutForDeliveryState::showStatus() {
    cout << "Order is out for delivery, please wait." << endl;
}

//////////////////////////////////////////////
void OutForDeliveryState::markAsOutForDelivery() {
    cout << "Order is now out for delivery." << endl;
    DeliveredState* deliveredState = new DeliveredState(order);
    order->setState(deliveredState);
    delete this;
}
void OutForDeliveryState::markAsDelivered() {
    cout << "Order is being delivered, please wait!" << endl;
}


DeliveredState::DeliveredState(IFoodOrder* _order) {
    order = _order;
}

void DeliveredState::getOrder() {
    cout << "Order has been delivered, enjoy your meal !" << endl;
}

void DeliveredState::checkOrder() {
    cout << "Order has been delivered, enjoy your meal !" << endl;
}

void DeliveredState::cancelOrder() {
    cout << "Order has been delivered, enjoy your meal !" << endl;
}

void DeliveredState::showStatus() {
    cout << "Order has been delivered, enjoy your meal !" << endl;
}

//////////////////////////////////////////////
void  DeliveredState::markAsOutForDelivery() {
    cout << "Can't mark as out for delivery after delivered." << endl;
}
void DeliveredState::markAsDelivered() {
    cout << "Order has been delivered, enjoy your meal !" << endl;
}