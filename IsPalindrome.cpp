#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

class Solution
{
  public:
    bool isPalindrome(std::string s)
    {
        std::string S{};
        std::string revS{};
        for (size_t i = 0; i < s.size(); i++)
        {
            if (std::isalnum(s.at(i)))
            {
                S.push_back(std::tolower(s[i]));
                revS.insert(revS.begin(), std::tolower(s[i]));
            }
        }
        return S == revS;
    }
};

int main()
{
    Solution sol;

    std::string s{"A man, a plan, a canal: Panama"};
    std::cout << std::boolalpha << sol.isPalindrome(s) << '\n';

    std::string s2{"race a car"};
    std::cout << sol.isPalindrome(s2) << '\n';

    std::string s3{""};
    std::cout << sol.isPalindrome(s3) << '\n';

    return 0;
}

// amanaplanacanalpanama
// amanaplanacanalpanama