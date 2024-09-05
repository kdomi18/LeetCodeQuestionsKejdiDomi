#include <iostream>
#include <string>

class Solution
{
  public:
    bool isSubsequence(const std::string &s, std::string t)
    {
        if (s.size() > t.size())
        {
            return false;
        }
        if (s.size() == t.size())
        {
            return s == t;
        }

        for (std::size_t i{0}; i < s.size(); i++)
        {
            auto position{t.find(s[i])};
            if (position == t.npos)
            {
                return false;
            }
            else
            {
                t.erase(t.begin(), t.begin() + static_cast<std::string::difference_type>(position));
            }
        }
        return true;
    }
};

int main()
{
    Solution sol{};
    std::cout << std::boolalpha;

    std::cout << sol.isSubsequence("abc", "ahbgdc"); // true
    std::cout << sol.isSubsequence("axc", "ahbgdc"); // false
}