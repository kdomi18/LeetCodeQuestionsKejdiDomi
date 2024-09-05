#include <iostream>

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
  private:
    int mCount{0};

  public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        mCount += 1;
        if (root->right)
        {
            root->right->val = 0;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            if (mCount == 1)
            {
                return 0;
            }

            return root->val;
        }
        else
        {
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
            ;
        }
    }
};

int main()
{
    Solution sol{};
    TreeNode *root{
      new TreeNode{3, new TreeNode{9, nullptr, nullptr},
                   new TreeNode{20, new TreeNode{15, nullptr, nullptr}, new TreeNode{7, nullptr, nullptr}}}};

    std::cout << sol.sumOfLeftLeaves(root);
}