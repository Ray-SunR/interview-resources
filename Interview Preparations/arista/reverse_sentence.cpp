#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(void)
{
	vector<string> container;
	string sentence;
	string word;
	getline(cin, sentence);
	stringstream ss(sentence);
	cout << "original:" << sentence << endl;
	while (ss >> word)
	{
		container.push_back(word);
	}
	sentence.erase();
	for (int i = container.size() - 1; i >= 0; i--)
	{
		sentence += container[i] + " ";
	}
	cout << "after: " << sentence << endl;
	return 0;
}
