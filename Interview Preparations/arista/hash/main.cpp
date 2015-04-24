#include "hash.h"
#include <iostream>

using namespace std;

int main(void)
{
	Hash_Table<string,double> hash;
	hash.add("Renchen Sun",5195919660);
	hash.add("Yuchen Liu",2269784716);
	hash.add("Renchen Sun",2269784716);
	hash.add("Cindy Tian",123456778);
	hash.print("Renchen Sun");
	hash.del("Renchen Sun",5195919660);	
	hash.print("Renchen Sun");
	hash.del("Renchen Sun",2269784716);
	hash.print("Renchen Sun");
	list<double> l = hash.find("Renchen Sun");
	hash.print("Yuchen Liu");
	hash.modify("Yuchen Liu",2269784716,5195919660);
	hash.print("Yuchen Liu");
	return 0;
}
