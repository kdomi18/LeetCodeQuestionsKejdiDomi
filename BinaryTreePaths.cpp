#include <iostream>
#include <string>
#include <vector>
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

[[maybe_unused]] auto print = [](std::vector<std::string> vec) {
    for (auto &&i : vec)
    {
        std::cout << i << '\n';
    }
    std::cout << '\n';
};

class Solution
{
  public:
    std::vector<std::string> binaryTreePaths(TreeNode *root)
    {
        std::vector<std::string> result{};
        std::string currentPath{};

        if (root == nullptr)
        {
            return result;
        }

        currentPath += std::to_string(root->val);

        if (root->left==nullptr && root->right==nullptr)
        {
            result.emplace_back(currentPath);
        }
        
        if (root->left != nullptr)
        {
            dfs(root->left, currentPath, result);
        }

        if (root->right != nullptr)
        {
            dfs(root->right, currentPath, result);
        }

        return result;
        
    }

    void dfs(TreeNode *node, std::string currentPath, std::vector<std::string> &result)
    {
        currentPath += std::string{"->"} + std::to_string(node->val);

        if (node->left==nullptr && node->right==nullptr)
        {
            result.emplace_back(currentPath);
            return;
        }

        if (node->left != nullptr)
        {
            dfs(node->left, currentPath, result);
        }

        if (node->right != nullptr)
        {
            dfs(node->right, currentPath, result);
        }
    }
};

int main()
{
    Solution sol;
    TreeNode *root{new TreeNode{1, new TreeNode{2, new TreeNode{4}, new TreeNode{5}}, new TreeNode{3}}};

    print(sol.binaryTreePaths(root));
}
