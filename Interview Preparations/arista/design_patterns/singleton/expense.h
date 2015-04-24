#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <string>
#include "wallet.h"

class Expense
{
	int amount;
	std::string describe;
	Wallet* w;
public:
	Expense(int amount = 0, std::string describe = "No description"):amount(amount),describe(describe),w(Wallet::getInstance()){}
	void pay();
};

#endif
