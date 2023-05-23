#include "Prince.h"
#include "Gate.h"
using namespace std;
class HandleGame
{
private:
	int n;
	Gate** x;
	Prince X;
	int typeGate[1000];
public:
	HandleGame();
	~HandleGame();
	void inputGate();
	void printGate();
	//bool handleCondition();

	void handleCondition();
};
