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
    void walk(TreeNode *root, std::vector<int> &vals)
    {
        if (!root)
        {
            return;
        }

        vals.emplace_back(root->val);
        walk(root->left, vals);
        walk(root->right, vals);
    }

  public:
    int getMinimumDifference(TreeNode *root)
    {
        std::vector<int> vals{};
        walk(root, vals);
        int min{100001};
        for (std::size_t i{}; i < vals.size(); i++)
        {
            for (std::size_t j{}; j < vals.size(); j++)
            {
                if (j != i)
                {

                    if (min > std::abs(vals.at(i) - vals.at(j)))
                    {
                        min = std::abs(vals.at(i) - vals.at(j));
                    }
                }
            }
        }

        return min;
    }
};

int main()
{
    Solution sol{};
    TreeNode *root{
      new TreeNode{236, new TreeNode{104, nullptr, new TreeNode{227}}, new TreeNode{701, nullptr, new TreeNode{911}}}};
    std::cout << sol.getMinimumDifference(root);
    return 0;
}

// [236,104,701,null,227,null,911]