#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Solution
{
  public:
    int longestPalindrome(const std::string &s)
    {
        if (s.size() < 2)
        {
            return s.size();
        }

        char ch{};
        std::string::size_type pos{};
        std::vector<std::size_t> lookedPositions{};
        int retLen{1};
        for (std::size_t i{0}; i < s.size(); i++)
        {
            if (std::ranges::find(lookedPositions, i) != lookedPositions.end())
            {
                continue;
            }

            if (i < s.size() - 1)
            {
                ch = s.at(i);
                pos = s.find(ch, i + 1);
                if (pos != s.npos)
                {
                    lookedPositions.emplace_back(i);
                    lookedPositions.emplace_back(pos);
                    retLen += 2;
                }
            }
        }
        return retLen > s.size() ? s.size() : retLen;
    }
};

int main()
{
    Solution sol{};
    std::cout << sol.longestPalindrome("abccccdd") << '\n';
    std::cout << sol.longestPalindrome("aDcccDcdd") << '\n';
}