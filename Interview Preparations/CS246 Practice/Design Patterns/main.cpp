#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	int i = 0;
	for (i = 0; i < 2; i += 1)
		cout << i << endl;
	ifstream in("story.txt");
	ofstream out("nice.txt");
	if (!in.is_open())
		cout << "story.txt does not exist!" << endl;
	string word;
	while(in >> word)
	{
		if (word == "uck")
		{
			out << "DELETED" << endl;
		}
		else
			out << word << endl;
	}
	in.close();
	out.close();
}
