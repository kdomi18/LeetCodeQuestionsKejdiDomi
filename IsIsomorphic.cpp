#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
  public:
    bool isIsomorphic(std::string s, std::string t)
    {
        std::unordered_map<char, char> dict{};
        std::unordered_map<char, char> dict2{};

        for (size_t i{0}; i < s.size(); i++)
        {
            dict.insert({s[i], t[i]});
            dict2.insert({t[i], s[i]});
        }

        // for (auto &p : dict)
        // std::cout << ' ' << p.first << " => " << p.second << '\n';

        for (auto &ch : s)
        {
            ch = dict.at(ch);
        }

        return s == t && dict.size() == dict2.size();
    }
};

int main()
{
    Solution sol;
    std::cout << std::boolalpha;
    std::cout << sol.isIsomorphic("egg", "add") << '\n';
    std::cout << sol.isIsomorphic("foo", "bar") << '\n';
    std::cout << sol.isIsomorphic("paper", "title") << '\n';
    std::cout << sol.isIsomorphic("badc", "baba") << '\n';

    return 0;
}
