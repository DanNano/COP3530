/*
		Project 1 AVL Tree by Daniel Laforce
		COP3530 Fall 2022
		10/9/2022
*/

#include <iostream>
#include <string>
#incude <vector>
#include <queue>
#include "AVL.h"
using namespace std;

//Extra function to main that helps find out if the Name entered is valid
bool ValidName(const string& info)
{
	for (char VAL : info)
	{
		if ((int)VAL < 65 || ((int)VAL > 90 && (int)VAL < 97) || (int)VAL > 122)
		{
			if ((int)VAL == 32)
			{
				continue;
			}
			return false;
		}
	}
	return true;
}
//Extra function to main that helps find out if the ID entered is valid
bool ValidID(const string& info)
{
	int counter = 0;
	for (char VAL : info)
	{
		if ((int)VAL < 48 || (int)VAL > 57)
		{
			if ((int)VAL == 32)
			{
				continue;
			}
			return false;
		}
		counter++;
	}
	if (counter != 8) //ID must be at least length 8
	{
		return false;
	}
	return true;
}

int main()
{
	AVL tree;
	string ID;
	string NAME;
	string input;
	string CMD;
	int InputNum;
	cin >> InputNum;

	for (int i = 0; i < InputNum; i++)
	{
		cin >> CMD;
		auto* node = new Node(); //This way it knows what type of node it is without linking
		if (CMD == "insert")
		{
			getline(cin, input);
			int Front = input.find_first_of('"');
			int Back = input.find_last_of('"');
			NAME = input.substr(Front + 1, Back - 2);
			ID = input.substr(Back + 1, input.length() - 1);
			if (!ValidID(ID)) //If ID is not valid
			{
				cout << "unsuccessful" << endl;
				continue;
			}
			if (NAME.empty()) //If no name was entered
			{
				cout << "unsuccessful" << endl;
				continue;
			}
			if (!ValidName(NAME)) //If name is not valid
			{
				cout << "unsuccessful" << endl;
				continue;
			}
			node->Name = NAME;
			node->UFID = stoi(ID);
			tree.root = tree.Insert(tree.root, node);
		}
		else if (CMD == "remove")
		{
			string RemVal;
			getline(cin, RemVal);
			if (!ValidID(RemVal))
			{
				cout << "unsuccessful" << endl;
				continue;
			}
			tree.root = tree.Remove(tree.root, stoi(RemVal));
		}
		else if (CMD == "search")
		{
			string SVal;
			getline(cin, SVal);
			int Front = SVal.find_first_of('"');
			int Back = SVal.find_last_of('"');
			if (Front > -1)
			{
				tree.SearchByName(tree.root, SVal.substr(Front + 1, Back - 2));
			}
			else
			{
				if (!ValidID(SVal))
				{
					cout << "unsuccessful" << endl;
					continue;
				}
				tree.SearchByID(tree.root, stoi(SVal));
			}
			if (!tree.Worked)
			{
				cout << "unsuccessful" << endl;
      }
			tree.Worked = false; //If you reach the end, something went wrong.
		}
		else if (CMD == "printPreorder")
		{
			tree.PrintPRE(tree.root);
			cout << endl;
		}
		else if (CMD == "printInorder")
		{
			tree.PrintIN(tree.root);
			cout << endl;
		}
		else if (CMD == "printPostorder")
		{
			tree.PrintPOST(tree.root);
			cout << endl;
		}
		else if (CMD == "printLevelCount")
		{
			tree.LevelCount(tree.root);
		}
		else if (CMD == "removeInorder")
		{
			int NthTerm; //Remove this value from a tree
			cin >> NthTerm;
			tree.RemoveIN(tree.root, NthTerm);
		}
	}
	return 0;
}
