#include <iostream>
#include "expense.h"

using namespace std;

void Expense::pay()
{
	cout << describe << " paid!" << endl;
	w->addMoney(-amount);
}
