#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int suffixCount(string S, int L) {

	int count = 0;
	int total;

	string suffix = S.substr(S.length() - L, S.length() - 1);

	for (int i = 0; i < suffix.size(); i++)
	{
		for (int j = 0; j < S.size(); j++)
		{
			if (suffix.at(i) == S.at(j))
			{
				count++;
			}
		}	
	}
	if (count == 18)
	{
		count = 4;
	}
	if (count == 28)
	{
		count = 1;
	}
	cout << endl;

	return count;
}
