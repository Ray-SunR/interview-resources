#include <iostream>
#include "wallet.h"
#include "expense.h"

using namespace std;


int main(void)
{
	Wallet* w = Wallet::getInstance();
	w->addMoney(500);
	cout << "Wallet now contains:" << w->getMoney() << " dollars" << endl;
	Expense* e1 = new Expense(50,"Car");
	Expense* e2 = new Expense(100,"Montarge");
	Expense* e3 = new Expense(150,"Test");
	e1->pay();	
	cout << "Wallet now contains: " << w->getMoney() << " dollars" << endl;
	e2->pay();
	cout << "Wallet now contains: " << w->getMoney() << " dollars" << endl;
	e3->pay();
	cout << "Wallet now contains: " << w->getMoney() << " dollars" << endl;
	delete e1;
	delete e2;
	delete e3;
	return 0;
}
