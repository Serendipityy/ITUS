#include "func.h"

FoodOrder::FoodOrder()
{
	state = WAITING_ORDER;
}
void FoodOrder::getOrder()
{
	switch (state)
	{
	case WAITING_ORDER:
		cout << "Order received, it will be placed soon." << endl;
		state = ORDER_PLACED;
		break;
	case ORDER_PLACED:
		cout << "Order is already placed, please wait for it to be prepared." << endl;
		break;
	case FOOD_PREPARATION:
		cout << "Order is being prepared, please wait." << endl;
		break;
	case OUT_FOR_DELIVERY:
		cout << "Order is out for delivery, please wait." << endl;
		break;
	case DELIVERED:
		cout << "Order has been delivered, enjoy your meal !" << endl;
	}
}
void FoodOrder::checkOrder()
{
	switch (state)
	{
	case WAITING_ORDER:
		cout << "Your order is still being processed." << endl;
		break;
	case ORDER_PLACED:
		state = FOOD_PREPARATION;
		break;
	case FOOD_PREPARATION:
		state = OUT_FOR_DELIVERY;
		break;
	case OUT_FOR_DELIVERY:
		state = DELIVERED;
		break;
	case DELIVERED:
		cout << "Order has been delivered, enjoy your meal !" << endl;
	}
}
void FoodOrder::cancelOrder()
{
	switch (state)
	{
	case WAITING_ORDER:
		cout << "Order cancelled." << endl;
		state = -1;
		break;
	case ORDER_PLACED:
		cout << "Order cancelled." << endl;
		state = -1;
		break;
	case FOOD_PREPARATION:
		cout << "Can't cancel after placing." << endl;
		break;
	case OUT_FOR_DELIVERY:
		cout << "Can't cancel after placing." << endl;
		break;
	case DELIVERED:
		cout << "Order has been delivered, enjoy your meal !" << endl;
	}
}
void FoodOrder::showStatus()
{
	switch (state)
	{
	case WAITING_ORDER:
		cout << "Waiting for order to be placed." << endl;
		break;
	case ORDER_PLACED:
		cout << "Order placed, waiting for it to be prepared." << endl;
		break;
	case FOOD_PREPARATION:
		cout << "Order is being prepared, please wait." << endl;
		break;
	case OUT_FOR_DELIVERY:
		cout << "Order is out for delivery, please wait." << endl;
		break;
	case DELIVERED:
		cout << "Order has been delivered, enjoy your meal !" << endl;
	}
}