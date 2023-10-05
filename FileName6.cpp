#include <iostream>
#include <string>
using namespace std;

int main()
{
	string text{};
	getline(cin, text);
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == ' ')
		{
			text[i] = '\t';
		}
	}
	cout << text << endl;
	
	string str{};
	getline(cin, str);
	int count = 0;
	int pos = str.find('and');
	while (pos != string::npos) {
		count++;
		pos = str.find("and", pos + 1);
	}
	cout << "Ands: " << count << endl;

	/*string strok{};
	getline(cin, strok);
	int pos1 = strok.find('A');
	while (pos1 != string::npos) {
		strok.erase();
		pos1 = str.find("and", pos1 + 1);
	}*/
}