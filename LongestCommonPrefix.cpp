#include <iostream>
#include <string>
#include <vector>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        std::string current{strs[0]};
        size_t cnt{strs[0].length()};
        strs.erase(strs.begin());
        for (auto &&str : strs)
        {
            cnt = 0;
            while (str[cnt] == current[cnt])
            {
                cnt++;
                if (cnt == str.length() || cnt == current.length())
                {
                    break;
                }
                
            }
            current = current.substr(0,cnt);
        }
        return current.substr(0,cnt);
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[])
{
    Solution sol;
    std::vector<std::string> myVec {"dog","racecar","car"};
    std::string val = sol.longestCommonPrefix(myVec);
    std::cout << val;
    return 0;
}
