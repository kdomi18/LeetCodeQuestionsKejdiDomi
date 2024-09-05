#include <iostream>
#include <string>
#include <stack>
#include <map>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::map<char, int> myMap = {
            {'(', 1},
            {')', -1},
            {'{', 2},
            {'}', -2},
            {'[', 3},
            {']', -3}};

        std::stack<int> myStack;
        for (auto &&i : s)
        {
            int candidate{myMap.at(i)};

            if (myStack.empty())
            {
                myStack.emplace(candidate);
            }
            else
            {
                if (myStack.top() + candidate == 0 && candidate < 0)
                {
                    myStack.pop();
                }
                else
                {
                    myStack.emplace(candidate);
                }
            }
        }

        return myStack.empty();
    }
};

int main()
{
    std::string myStr{"(){}}{"};
    Solution sol;
    std::cout << std::boolalpha << sol.isValid(myStr) << '\n';
    return 0;
}