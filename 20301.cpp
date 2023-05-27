#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string Instring;
	int totalIdx = 0;
	cin >> Instring;

	map<char, int> numberCount;

	for (auto ch : Instring)
	{
		if (ch == -52 || ch == '\0')
			continue;
		numberCount[ch]++;
	}

	for(int i = 0; i < numberCount['0'] / 2; i++) 
	{
		int idx = Instring.rfind('0');
		if (idx != string::npos)
		{
			Instring.erase(idx, 1);
		}

	}

	for (int i = 0; i < numberCount['1'] / 2; i++) {
		int idx = Instring.find('1');
		if (idx != string::npos)
		{
			Instring.erase(idx, 1);
		}

	}
	cout << Instring << endl;
		
}
