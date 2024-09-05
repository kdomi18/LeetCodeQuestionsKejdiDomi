#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
  public:
    bool canConstruct(std::string ransomNote, std::string magazine)
    {
        char ch{};
        for (std::size_t i{0}; i < ransomNote.size(); i++)
        {
            ch = ransomNote.at(i);
            auto it{std::ranges::find(magazine, ch)};
            if (it != magazine.end())
            {
                magazine.erase(it);
            }
            else
            {
                return false;
            }
        }
        return true;
        
    }
};

int main()
{
    Solution sol{};
    std::cout << std::boolalpha;

    std::cout << sol.canConstruct("a", "b") << '\n';    // false
    std::cout << sol.canConstruct("aa", "ab") << '\n';  // false
    std::cout << sol.canConstruct("aa", "aab") << '\n'; // true

    return 0;
}