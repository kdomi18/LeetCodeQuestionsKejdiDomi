#include <iostream>
#include <math.h>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};


class Solution
{
  public:
    bool isBalanced(TreeNode *root)
    {
        if (root)
        {
            return std::abs(maxDepth(root->left) - maxDepth(root->right)) <=1 && isBalanced(root->left) && isBalanced(root->right);
        }
        else
        {
            return true;
        }
        
    }

  private:
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};