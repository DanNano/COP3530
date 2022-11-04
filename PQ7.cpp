/*
				Programming Quiz #7 by Daniel Laforce
				COP3530 Fall 2022 -  Submitted: 11/4/2022
				Went with the map method

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <set> //Not used
#include <unordered_map> //Not used
#include <map>
using namespace std;

string findTheDigits(string x, string y) // Removed std:: as I added namespace std
{
	map<char, int> StringReadMap; //map function is the way I went with this problem
	string AddedOutput = ""; //This will be the final answer, numbers added on.
	for (int i = 0; i < (int)x.length(); i++) //Goes through the length of x, which is the original digit.
	{
		StringReadMap[x[i]]++;
	}
	for (int i = 0; i < (int)y.length(); i++) //Reads y, which is x string digit with n to 0 added to it.
	{
		if (StringReadMap[y[i]] == 0)
		{
			AddedOutput += y[i]; //Adding extra value(or decrementing map in else) to output for processing.
			continue;
		}
		else
		{
			StringReadMap[y[i]]--;
		}
	}
	sort(AddedOutput.begin(), AddedOutput.end()); //MUST SORT, Test cases will fail if the answer is not sorted
	//To conserve time, using STL Sort instead of creating a sorting method that was used in previous module.

	return AddedOutput;
}
//Edit: May fail with negative numbers.
//Side note: Is there a way to see main function? Can only really test in Gradescope/EduGator
