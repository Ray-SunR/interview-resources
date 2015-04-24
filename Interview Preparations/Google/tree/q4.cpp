#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


/*Question:
We have an array representing customer’s shopping records.
For example, it’s an array like this:
custA, item1,
custB, item1,
custA, item2,
 custB, item3,
 custC, item1,
 custC, item3,
 custD, item2,
This array indicates that customer A bought item 1, customer B bought item 1, customer A bought item 2, customer B bought
item 3, etc..
For a given item X and shopping records array, write code to find out what else (item Y) was bought mostly by the customers
who bought item X.
For example, in above example, if X is item 1 then Y should be item 3.
Rules:
1.  One customer can only buy one item once.
2.  The mostly brought item should not be item X.
3.  If no customer brought item X, then return “None”
4.  If all the customers who brought item X only brought item X, then return “None”
5.  The first line of input is the item X. The second line of input is the shopping record array, this shopping record array is
split by space.
6.  If there are many other mostly brought items which have equally brought times, then return any one of those items.
Examples:
Input1:
item1
custA item1 custB item1 custA item2 custB item3 custC item1 custC item3 custD item2
Output1:
item3
 
Input2:
item2
custA item1 custB item1 custC item1 custA item2 custB item3 custA item3
Output2:
item1   
(The output2 can be item3 too)*/

void input()
{
	map<string,vector<string> > maCust;//customers buy what items
	map<string,vector<string> > maItem;//who purchases items
	map<string,int> maResult;//store results
	string itemX;
	getline(cin,itemX);
	string custRecord;
	getline(cin,custRecord);
	stringstream ss(custRecord);
	string item;
	string cust;
	while (ss >> cust && ss >> item){maCust[cust].push_back(item);maItem[item].push_back(cust);}//store cust records and item records to map container
	if (maItem.find(itemX) == maItem.end())
	{
		cout << "None" << endl;
		return;
	}
	else
	{
		vector<string> vecCust = maItem[itemX];
		for (vector<string>::iterator i = vecCust.begin();i != vecCust.end();i++)
		{
			vector<string> vecItem = maCust[*i];//get the list of customers purchased items
			for (vector<string>::iterator j = vecItem.begin();j != vecItem.end();j++)
				maResult[*j]++;//increase the items that customers who purchase itemX purchase
		}
		int maxNum = -1;
		string resultItem;
		for (map<string,int>::iterator i = maResult.begin();i != maResult.end();i++)
		{
			if (i->first != itemX && maxNum < i->second) 
			{
				maxNum = i->second;
				resultItem = i->first;
			}
		}
		if (maxNum == -1)
			cout << "None" << endl;
		else
			cout << resultItem << endl;
	}	
}

int main(void)
{
	input();
	return 0;
}
