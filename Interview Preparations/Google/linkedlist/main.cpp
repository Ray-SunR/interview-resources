#include <iostream>
#include "linkedlist.h"

using namespace std;

int main(void)
{	
	try
	{
		LinkedList<string> list;
		/*list.addNodeFront("Renchen Sun");
		list.addNodeFront("Yuchen Liu");
		list.addNodeFront("Duke Du");
		list.addNodeFront("Kai");*/
		/*list.addNodeTail("AA");
		list.addNodeTail("BB");
		list.addNodeTail("DD");
		list.addNodeFront("CC");*/
		list.addNodePos("Renchen Sun",1);
		list.addNodePos("Renchen Sun",0);
		list.addNodePos("Yuchen Liu",0);
		list.addNodePos("Duke Du",1);
		list.addNodePos("Weibo",2);
		list.print();
		list.addNodePos("Kai",2);
		list.print();
		list.addNodePos("Ana",4);
		cout << "Length: " << list.getLength() << endl;
		list.print();
		list.removeFront();
		list.print();
		list.reverse();
		list.print();
		list.addNodeFront("Renchen Sun");
		list.addNodeTail("Renchen Sun");
		list.print();
		list.removeIf("Renchen Sun");
		list.print();
		//cout << "Finish.." << endl;
		/*list.removeTail();
		list.print();
		list.removeTail();
		list.print();
		list.removePos(1);
		list.print();
		list.removePos(0);
		list.print();
		list.reverse();
		list.print();*/
		
	}
	catch (exception& e)
	{	
		cout << e.what() << endl;
	}
}
