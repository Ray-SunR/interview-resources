#ifndef WALLET_H
#define WALLET_H

#include <iostream>

class Wallet
{
	static Wallet* instance;
	static void cleanUp();
	Wallet();
	int money;
public:
	static Wallet* getInstance();
	int getMoney() const {return money;}
	void addMoney(int amount){money += amount;}
};

#endif
