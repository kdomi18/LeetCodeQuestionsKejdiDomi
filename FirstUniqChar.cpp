#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
  public:
    int firstUniqChar(std::string s)
    {
        std::unordered_map<char, int> mp{};
        // mp[(char, index)] = count
        for (std::size_t i{0}; i < s.size(); i++)
        {
            if (mp.find(s[i]) == mp.end())
            {
                mp[s[i]] = 1;
            }
            else
            {
                mp[s[i]] += 1;
            }
        }

        for (std::size_t i{0}; i < s.size(); i++)
        {
            if (mp.at(s[i]) == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol{};

    std::cout << sol.firstUniqChar("leetcode") << '\n';     // 0
    std::cout << sol.firstUniqChar("aabb") << '\n';         // -1
    std::cout << sol.firstUniqChar("loveleetcode") << '\n'; // 2

    return 0;
}