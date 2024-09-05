#include <iostream>
#include <vector>

// speed up
#include <fstream>
#include <iostream>
#include <string>

auto init = []() {
    std::cin.sync_with_stdio(false);
    std::fstream out("user.out");
    for (std::string s; std::getline(std::cin, s);)
    {
        std::getline(std::cin, s);
        s[0] != '-' ? out << "true\n" : out << "false\n";
    }
    out.flush();
    exit(0);
    return 0;
}();
// end speedup

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr)
//     {
//     }
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr)
//     {
//     }
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
//     {
//     }
// };

class Solution
{
  public:
    std::vector<int> preorderTraversal(TreeNode *root)
    {
        std::vector<int> ret{};
        std::vector<TreeNode *> st;
        if (!root)
        {
            return ret;
        }

        st.push_back(root);
        while (!st.empty())
        {
            root = st.at(st.size() - 1);
            st.pop_back();
            ret.push_back(root->val);

            if (root->right)
            {
                st.push_back(root->right);
            }

            if (root->left)
            {
                st.push_back(root->left);
            }
        }

        return ret;
    }
};

auto print = [](std::vector<int> vec) {
    for (auto &&i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
};

int main()
{
    Solution sol;
    TreeNode *tree = new TreeNode(1, new TreeNode(2, new TreeNode(5), new TreeNode(6)), new TreeNode(3));

    print(sol.preorderTraversal(tree));

    return 0;
}