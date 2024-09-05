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
    int maxDepth(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main()
{
    Solution sol;
    TreeNode *normalTree = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    TreeNode *onlyOneNode = new TreeNode(2);

    TreeNode *straightLine = new TreeNode(
      1, new TreeNode(2, new TreeNode(3, new TreeNode(4, new TreeNode(5), nullptr), nullptr), nullptr), nullptr);

    TreeNode *empty = nullptr;

    std::cout << sol.maxDepth(normalTree) << '\n';
    std::cout << sol.maxDepth(onlyOneNode) << '\n';
    std::cout << sol.maxDepth(straightLine) << '\n';
    std::cout << sol.maxDepth(empty) << '\n';

    return 0;
}