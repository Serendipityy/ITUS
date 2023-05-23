#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Item {
private:
    int weight;
    int value;

public:
    Item(int value, int weight) : value(value), weight(weight) {}
    ~Item() = default;
    Item() = delete;
    int getWeight() { return weight; }

    int getValue() { return value; }

    double getValueOfItem(int items = 1) const {
        return static_cast<double>(value * items) / weight;
    }

    bool operator<(const Item& a) {
        return getValueOfItem() < a.getValueOfItem();
    }
};

double get_optimal_value(int capacity, /*vector<int> weights, vector<int> values*/ vector<Item>& items) {
    double value = 0.0;

    // write your code here
    sort(items.begin(), items.end());
    reverse(items.begin(), items.end());
    auto it = items.begin();
    while (capacity > 0) {
        if (capacity >= it->getWeight()) {
            capacity -= it->getWeight();
            value += it->getValue();
        }
        else {
            value += it->getValueOfItem(capacity);
            capacity = 0;
        }
        it = next(it);
    }
    return value;
}

int main() {
    int n;
    int capacity;
    std::cin >> n >> capacity;
    //vector<int> values(n);
    //vector<int> weights(n);
    vector<Item> items;
    int value, weight;
    for (int i = 0; i < n; i++) {
        /*std::cin >> values[i] >> weights[i];*/
        cin >> value >> weight;
        items.emplace_back(value, weight);
    }

    //double optimal_value = get_optimal_value(capacity, weights, values);
    double optimal_value = get_optimal_value(capacity, items);
    std::cout.precision(10);
    std::cout << optimal_value << std::endl;
    return 0;
}
