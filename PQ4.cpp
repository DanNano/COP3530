//Daniel Laforce Programming Quiz 4
//Submitted 9/23/2022
//Used the queue format that was in the septik videos/questions. Much easier than vector movement. 

#include <iostream>
#include <queue> //Used as primary structure for storage. 
#include <vector> //Not used, code left that did use it however
#include <stack> //Not used, just in case it was needed. 
using namespace std;

class TreeNode 
 {
    public:
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

// This will be called in main to construct the tree
TreeNode* insert(TreeNode* root, int data) 
{
  if (root == nullptr)
    return new TreeNode(data);
  if (root->val < data)
    root->right = insert(root->right, data);
  else 
    root->left = insert(root->left, data);
  return root;
}

// This will be called in main to deallocate memory
void destruct(TreeNode* root) 
{
  if (root->left) 
    destruct(root->left);
  if (root->right) 
    destruct(root->right);
  delete root;
}
int sumOfLevel(TreeNode* root, int level) 
{
  int depth = 0; // Set at 0 as level(root) starts there
  int total = 0;
	  if (root == nullptr)
    {
      return -1; // If there is actually no tree
    }
  queue<TreeNode*> NodesOnLevel; 
  NodesOnLevel.push(root); //First push the root into the queue
  while (!NodesOnLevel.empty()) //Queue with Nodes will be popped on the right level
  {
    int QueueTotal = NodesOnLevel.size();
    while (QueueTotal--)
    {
      TreeNode* front = NodesOnLevel.front(); //Sets to first on Queue(or start of program, the root)
      NodesOnLevel.pop();
      if (depth == level)
      {
        total += front->val; // if depth is the same as level, the sum will be totaled up.
      }
      else
      {
        if (front->left) // Move queue to the left of tree
        {
          NodesOnLevel.push(front->left);
        }
        if (front->right) // move queue to the right of tree
        {
          NodesOnLevel.push(front->right);
        }
      }
    }
    depth++; // Go up a level
  }
  // 1st version of code I couldn't get to work

  /*vector<int> NodePass;

  NodePass.push_back(root->val);

  while (!NodePass.empty())

  {

    int VectorSize = NodePass.size();


    while (VectorSize--)

    {

      TreeNode* TopOfVector = NodePass.front();

      NodePass.pop_back();


      if (depth == level)

      {

        sum += TopOfVector->val;

      }

      else

      {

        if (TopOfVector->left)

        {

          NodePass.push_back(TopOfVector->left);

        }

        if (TopOfVector->right)

        {

          NodePass.push_back(TopOfVector->right);

        }

      }

    }

    depth++;

  }*/
  if (total > 0)
  {
    return total; //end
  }
  else
  {
    return -1; //If there are no nodes at level L.
  }
}
