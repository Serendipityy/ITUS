#pragma once

#include <iostream>

using namespace std;

class FoodOrder
{
private:
	enum FoodOrderState
	{
		WAITING_ORDER,
		ORDER_PLACED,
		FOOD_PREPARATION,
		OUT_FOR_DELIVERY,
		DELIVERED
	};
	int state;
public:
	FoodOrder();
	void getOrder();
	void checkOrder();
	void cancelOrder();
	void showStatus();
};