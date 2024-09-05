#include <iostream>
#include <unordered_map>
#include <vector>

template <typename T>
[[maybe_unused]] auto print = [](std::vector<T> vec) {
    for (auto &&i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
};

// Definition for a binary tree node.
struct [[maybe_unused]] TreeNode
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
    void bfs(std::unordered_map<int, int> &mp, TreeNode *root)
    {
        if (!root)
        {
            return;
        }

        mp[root->val] += 1;

        bfs(mp, root->left);
        bfs(mp, root->right);
    }

  public:
    std::vector<int> findMode(TreeNode *root)
    {
        std::unordered_map<int, int> mp{}; // el -> count
        bfs(mp, root);
        int max{-100001};
        std::vector<int> rv{};
        for (auto &&k : mp)
        {
            std::cout << "key- " << k.first << ' ' << "val- " << k.second << '\n';
            if (max < k.second)
            {
                rv.clear();
                max = k.second;
                rv.push_back(k.first);
            }
            else if (max == k.second)
            {
                rv.push_back(k.first);
            }
        }

        return rv;
    }
};

int main()
{
    Solution sol{};
    TreeNode *root{new TreeNode{1, nullptr, new TreeNode{2, new TreeNode{2, new TreeNode{1, nullptr, nullptr}, nullptr}, nullptr}}};

    print<int>(sol.findMode(root));

    return 0;
}