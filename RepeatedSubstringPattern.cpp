#include <iostream>
#include <string>

class Solution
{
  private:
    bool check(std::string::size_type i, const std::string &s)
    {
        std::string dummy{};
        std::string sub{s.substr(0, i)};
        for (std::size_t k{0}; k < s.size() / i; k++)
        {
            dummy += sub;
        }
        return s.compare(dummy) == 0;
    }

  public:
    bool repeatedSubstringPattern(std::string s)
    {
        for (std::size_t i{1}; i < (s.size() / 2 + 1); i++)
        {
            if (s.size() % i == 0)
            {
                if (check(i, s))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol{};
    std::cout << std::boolalpha;

    std::cout << sol.repeatedSubstringPattern("abab") << '\n';      // true
    std::cout << sol.repeatedSubstringPattern("abcab") << '\n';       // false
    std::cout << sol.repeatedSubstringPattern("abababababc") << '\n'; // false
    std::cout << sol.repeatedSubstringPattern("ababababab") << '\n';  // true
    return 0;
}