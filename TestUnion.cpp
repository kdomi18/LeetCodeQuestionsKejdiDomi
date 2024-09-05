#include <cstddef>
#include <iostream>
#include <variant>
#include <vector>

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

TreeNode ArrayToBinTree(std::vector<std::variant<int, nullptr_t>> myVec)
{
    for (size_t i{0}; i < myVec.size(); i++)
    {
        if (myVec.at(i).index() == 1)
        {
            std::cout << "null, ";
        }
        else
        {
            int val{std::get<int>(myVec.at(i))};
            if (i == myVec.size() - 1)
            {
                std::cout << val << '\n';
            }
            else
            {
                std::cout << val << ", ";
            }
        }
    }

    TreeNode *myNode{};
    TreeNode *currLeft{};
    TreeNode *currRight{};

    std::vector<TreeNode *> vecOfNodes{myNode, currLeft, currRight};
    size_t repIndex{};

    for (size_t index{0}; index < myVec.size(); index++)
    {
        repIndex = index % 3;

        if (myVec.at(index).index() == 1)
        {
            continue;
        }
        else
        {
            myNode = new TreeNode{std::get<int>(myVec.at(index))};
        }
    }

    return {};
}

int main()
{
    ArrayToBinTree({1, 2, nullptr, 3, nullptr});
}
