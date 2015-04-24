#include "wallet.h"
#include <iostream>
#include <cstdlib>

Wallet* Wallet::instance = NULL;

Wallet::Wallet():money(0){}

Wallet* Wallet::getInstance()
{
	if (!instance)
	{
		instance = new Wallet;
		atexit(cleanUp);
	}
	return instance;
}

void Wallet::cleanUp()
{
	delete instance;
}


