#include <algorithm>
#include <iostream>
#include <utility>
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

class Solution
{
  public:
    TreeNode *sortedArrayToBST(std::vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return new TreeNode(nums.at(0));
            ;
        }

        if (nums.size() == 0)
        {
            return nullptr;
        }

        int mid{0};

        mid = nums[nums.size() / 2];

        std::pair<std::vector<int>, std::vector<int>> myPair{separateVectorInMiddle(nums)};

        return new TreeNode(mid, sortedArrayToBST(myPair.first), sortedArrayToBST(myPair.second));
    }

  private:
    std::pair<std::vector<int>, std::vector<int>> separateVectorInMiddle(std::vector<int> vec)
    {
        long half_size = vec.size() / 2;

        return {std::vector<int>(vec.begin(), vec.begin() + half_size),
                std::vector<int>(vec.begin() + half_size + 1, vec.end())};
    }
};

void printBreadthFirstBST(TreeNode *root, bool first = true)
{
    if (root)
    {
        if (first)
        {
            std::cout << root->val << ' ';
            first = false;
        }
        if (root->left)
        {
            std::cout << root->left->val << ' ';
        }
        if (root->right)
        {
            std::cout << root->right->val << ' ';
        }
        printBreadthFirstBST(root->left, false);
        printBreadthFirstBST(root->right, false);
    }
    else
    {
        return;
    }
}

int main()
{
    Solution sol;
    std::vector<int> vec1{-10, -3, -2, 0, 5, 9, 10};
    std::vector<int> vec2{-10};

    TreeNode *BST1{sol.sortedArrayToBST(vec1)};
    TreeNode *BST2{sol.sortedArrayToBST(vec2)};

    printBreadthFirstBST(BST1);
    std::cout << "pause\n";
    printBreadthFirstBST(BST2);

    return 0;
}