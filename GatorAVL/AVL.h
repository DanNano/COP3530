#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Node struct that acts as the basis for the AVL Tree
//Cannot put it in AVL Class or it causes errors
struct Node
{
	string Name;
	int UFID;
	Node* left;
	Node* right;

	Node()
	{
		Name = " ";
		UFID = 0;
		left = nullptr;
		right = nullptr;
	}
  
	Node(string newName, int newID)
	{
		Name = move(newName);
		UFID = newID;
		left = nullptr;
		right = nullptr;
	}
};

class AVL
{
public:
	//---------------------------------------------------Basic Constructor-----------------------------------------------------------//
	AVL() //Basic constructor
	{
		root = nullptr;
	}
	//------------------------------------------------Height/Balance functions---------------------------------------------------------//
	int Height(Node* node); //Find the height of the tree
	int Balance(Node* node); //Balance the tree if required
	//------------------------------------------------Rotation Functions----------------------------------------------------------//
	Node* RotateRight(Node* node); //Do a right rotation of the tree if required
	Node* RotateLeft(Node* node); //Do a left rotation of the tree if required
	//-------------------------------------------------Insert and Remove Functions------------------------------------------------//
	Node* Insert(Node* node, Node* next); //Insert function for the tree
	Node* Remove(Node* node, int RemVal); //Remove a node from the tree
	//----------------------------------------------------Search Functions------------------------------------------------------//
	Node* SearchByID(Node* node, int IDS); //Search the tree for a specific ID
	Node* SearchByName(Node* node, const string& NameSearch); //Search the tree for a specific Name in the tree
	//------------------------------------------------------Print Functions-----------------------------------------------------//
	void PrintIN(Node* node); //Print inorder in the tree
	void PrintPRE(Node* node); //Print Preorder in the tree
	void PrintPOST(Node* node); //Print postorder in the tree
	void RemoveIN(Node* node, int Nth); //Remove inorder in the tree
	void LevelCount(Node* node); //Prints the level count of the tree
	//--------------------------------------------------------Internal variables-----------------------------------------------//
	Node* root; //Root of the tree, first node
	bool Worked = false; //Bool variable if the function/method actually worked

private:

	//---------------------------------------------------------Helper functions------------------------------------------------//
	void InOrderRemove(Node* node, vector<Node*>& IDs); //Helper function to remove Nth value from a tree
	Node* findMin(Node* node); //Helper function to find the minimal node from a tree
	Node* findMax(Node* node); //Helper function to find the max node from a tree
};
