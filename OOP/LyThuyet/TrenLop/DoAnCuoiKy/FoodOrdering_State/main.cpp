#include"FoodOrder.h"

int main() {
    FoodOrder* order = new FoodOrder();
    // WaitingOrderState;
    order->getOrder();
    cout << endl;

    // OrderPlacedStatus
    order->showStatus();
    order->checkOrder();
    cout << endl;

    // FoodPreparationState
    order->showStatus();
    order->checkOrder();

    order->markAsOutForDelivery();
    cout << endl;

    // OutForDeliveryState
    order->showStatus();
    order->checkOrder();
    order->markAsDelivered();
    cout << endl;

    // DeliveredState
    order->showStatus();
    return 0;
}