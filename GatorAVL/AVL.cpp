#include "AVL.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int AVL::Height(Node* node) //Function to find the height of the Height of the tree via the Max std function
{
	if (node == nullptr)
	{
		return 0;
	}
	return 1 + max(Height(node->left), Height(node->right));
}

int AVL::Balance(Node* node) //Function that balances the tree if required
{
	if (node == nullptr)
	{
		return 0;
	}
	else
	{
		return Height(node->left) - Height(node->right);
	}
}

Node* AVL::RotateRight(Node* node) //Function to rotate the tree right if balance is off
{
	Node* temp = node->left;
	Node* temp2 = temp->right;
	temp->right = node;
	node->left = temp2;
	return temp;
}

Node* AVL::RotateLeft(Node* node) //Functino to rotate the tree left if balance if off
{
	Node* temp = node->right;
	Node* temp2 = temp->left;
	temp->left = node;
	node->right = temp2;
	return temp;
}

Node* AVL::Insert(Node* node, Node* next) //Main insert function to add Nodes to the tree
{
	if (node == nullptr)
	{
		node = next;
		cout << "successful" << endl;
		return node;
	}
	else
	{
		if (next->UFID < node->UFID)
		{
			node->left = Insert(node->left, next);
		}
		else if (next->UFID > node->UFID)
		{
			node->right = Insert(node->right, next);
		}
		else
		{
			cout << "unsuccessful" << endl;
			return node;
		}
	}
	//If rotation is required, this sets up everything
	int currBal = Balance(node);
	//Left-Left rotation
	if (currBal > 1 && next->UFID < node->left->UFID)
	{
		return RotateRight(node);
	}
	//Right-Right rotation
	if (currBal < -1 && next->UFID > node->right->UFID)
	{
		return RotateLeft(node);
	}
	//Left-Right rotation
	if (currBal > 1 && next->UFID > node->left->UFID)
	{
		return RotateRight(node);
	}
	//Right-Left rotation
	if (currBal < -1 && next->UFID < node->right->UFID)
	{
		node->right = RotateRight(node->right);
		return RotateLeft(node);
	}
	return node;
}
Node* AVL::Remove(Node* node, int RemVal) //Main removal function that removes a node from the tree
{
	if (node == nullptr)
	{
		cout << "unsuccessful" << endl;
		return nullptr;
	}
	else if (RemVal < node->UFID)
	{
	node->left = Remove(node->left, RemVal);
	}
	else if (RemVal > node->UFID)
	{
		node->right = Remove(node->right, RemVal);
	}
	//no child tree
	else if (node->left == nullptr && node->right == nullptr)
	{
		delete node;
		node = nullptr;
		cout << "successful" << endl;
		return node;
	}
	else if (node->left == nullptr) //one child
	{
		Node* temp = node;
		node = node->right;
	delete temp;
		cout << "successful" << endl;
		return node;
	}
	else if (node->right == nullptr) //one child
	{
		Node* temp = node;
		node = node->left;
		delete temp;
		cout << "successful" << endl;
		return node;
	}
	else //two child tree
	{
		Node* temp = findMin(node->right);
		node->UFID = temp->UFID;
		node->Name = temp->Name;
		node->right = temp->right;
		delete temp;
		cout << "successful" << endl;
		return node;
	}
	return node;
}

Node* AVL::SearchByID(Node* node, int IDS) //Main function that searches the tree for a particular ID and prints the name associated with it.
{
	if (node == nullptr)
	{
		return node;
	}
	else if (node->UFID == IDS)
	{
		cout << node->Name << endl;
		Worked = true;
		return node;
	}
	else if (IDS < node->UFID)
	{
		return SearchByID(node->left, IDS);
	}
	else
	{
		return SearchByID(node->right, IDS);
	}
}

Node* AVL::SearchByName(Node* node, const string& NameSearch) // Main function that searches the tree for a particular Name and prints the UFID
{
	if (node == nullptr)
	{
		return node;
	}
	else if (node->Name == NameSearch)
	{
		cout << node->UFID << endl;
		Worked = true;
	}
	SearchByName(node->left, NameSearch);
	SearchByName(node->right, NameSearch);
	return node;
}

Node* AVL::findMin(Node* node) //Helper function to find the min value nod in the tree
{
	while (node->left != nullptr)
	{
		node = node->left;
	}
	return node;
}

Node* AVL::findMax(Node* node) //Helper function to find the max value in the tree
{
	while (node->right != nullptr)
	{
		node = node->right;
	}
	return node;
}

void AVL::PrintIN(Node* node) //Main function to print Inorder in the tree
{
	if (node != nullptr)
	{
		PrintIN(node->left);
		if (node->left)
		{
			cout << ", ";
		}
		cout << node->Name;
		if (node->right)
		{
			cout << ", ";
		}
		PrintIN(node->right);
	}
}

void AVL::PrintPRE(Node* node) //Main function to print preorder in the tree
{
	if (node != nullptr)
	{
		cout << node->Name;
		if (node->left)
		{
			cout << ", ";
		}
		PrintPRE(node->left);
		if (node->right)
		{
			cout << ", ";
		}
		PrintPRE(node->right);
	}
}

void AVL::PrintPOST(Node* node) //Main function to print postorder in the tree
{
	if (node != nullptr)
	{
		PrintPOST(node->left);
		if (node->right)
		{
			cout << ", ";
		}
		PrintPOST(node->right);
		if (node->left)
		{
			cout << ", ";
		}
		cout << node->Name;
	}
}

void AVL::RemoveIN(Node* node, int Nth) //Function to remove the Nth term from the tree
{
	vector<Node*> IDs;
	InOrderRemove(node, IDs);
	Remove(node, IDs[Nth]->UFID);
}
void AVL::LevelCount(Node* node) //Function to print the level count of the tree
{
	cout << Height(node) << endl;
}

void AVL::InOrderRemove(Node* node, vector<Node*>& IDs) //Helper function that aids the RemoveIN function, removing nth term from the tree
{
	if (node == nullptr)
	{
		return;
	}
	InOrderRemove(node->left, IDs);
	IDs.push_back(node);
	InOrderRemove(node->right, IDs);
}
