#include <iostream>
#include <optional>
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

TreeNode *fromVec(std::vector<std::optional<int>> &vec)
{
    // [1,2,3,null,null,1, null]
    if (vec.empty())
    {
        return nullptr;
    }

    int val{};
    bool nullNode{false};
    if (vec.front().has_value())
    {
        val = vec.front().value();
    }
    else
    {
        nullNode = true;
    }
    vec.erase(vec.begin());

    if (nullNode)
    {
        return nullptr;
    }

    TreeNode *root = new TreeNode{val};
    root->right = fromVec(vec);
    root->left = fromVec(vec);

    return root;
}

void DFS(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    std::cout << root->val << ' ';
    DFS(root->left);
    DFS(root->right);
}

void BFS(TreeNode *root)
{
    if (!root)
    {
        return;
    }
    std::cout << root->val << ' ';
    if (root->left)
    {
        std::cout << root->left->val;
    }
    if (root->left)
    {
        std::cout << root->right->val;
    }
    BFS(root->left);
    BFS(root->right);
    
}

int main()
{
    std::vector<std::optional<int>> myVec{1, 2, 3, 4, 6, std::nullopt, 5};
    TreeNode *root = fromVec(myVec);
    DFS(root);
    std::cout << '\n';
    TreeNode *tst{
      new TreeNode{1, new TreeNode{2, new TreeNode{4}, new TreeNode{5}}, new TreeNode{3, nullptr, new TreeNode{6}}}};
    DFS(tst);

    return 0;
}