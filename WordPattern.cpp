#include <iostream>
#include <unordered_map>
#include <string>

class Solution
{
  public:
    bool wordPattern(std::string pattern, std::string s)
    {
        std::unordered_map<char, std::string> map1{};
        std::unordered_map<std::string, char> map2{};

        char ch{};
        std::string subStr{};

        std::string dummy{s};

        for (size_t i = 0; i < pattern.length(); i++)
        {
            ch = pattern[i];
            subStr = consume(s);

            if (map1.find(ch) != map1.end() && map1[ch] != subStr)
            {
                return false;
            }
            
            map1[ch] = subStr;
            map2[subStr] = ch;
        }

        if (dummy == reconstruct(map1, pattern) && map1.size()==map2.size())
        {
            return true;
        }

        return false;
    }

    std::string reconstruct(std::unordered_map<char, std::string> map, std::string pattern)
    {
        std::string ret{};
        for (size_t i = 0; i < pattern.length(); i++)
        {
            ret += map[pattern[i]];
            if (i != pattern.length()-1)
            {
                ret += " ";
            }
            
        }
        return ret;
    }

    std::string consume(std::string &str)
    {
        auto pos = std::next(str.begin(), static_cast<long>(str.find(' ')));
        if (str.find(' ') == str.npos)
        {
            return str;
        }

        std::string mySub{str.substr(0, static_cast<unsigned long>(std::distance(str.begin(), pos)))};
        str.erase(str.begin(), pos + 1);

        return mySub;
    }
};

int main()
{
    Solution sol{};
    std::cout << std::boolalpha;
    std::cout << sol.wordPattern("abbab", "dog cat cat dog cat") << '\n'; // true
    std::cout << sol.wordPattern("abba", "dog cat cat fish") << '\n';     // false
    std::cout << sol.wordPattern("abba", "dog dog dog dog") << '\n';      // fales"abaaa"
    std::cout << sol.wordPattern("abaaa", "dog cat cat dog dog") << '\n';      // fales"abaaa"

    return 0;
}