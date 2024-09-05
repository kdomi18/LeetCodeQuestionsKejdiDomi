#include <iostream>
#include <vector>

auto print = [](std::vector<int> vec) {
    for (auto &&i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
};

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
    std::vector<int> inorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        
        std::vector<int> ret{};
        retInTrav(root, ret);
        return ret;
    }

  private:
    void retInTrav(TreeNode *root, std::vector<int> &vec)
    {
        if (root->left)
            retInTrav(root->left, vec);
        if (root)
            vec.push_back(root->val);
        if (root->right)
            retInTrav(root->right, vec);
    }
};

int main()
{
    Solution sol;
    TreeNode *tn = new TreeNode(2, new TreeNode(1, new TreeNode(0), new TreeNode(2)), new TreeNode(3));
    std::vector<int> ans{sol.inorderTraversal(tn)};

    print(ans);

    return 0;
}