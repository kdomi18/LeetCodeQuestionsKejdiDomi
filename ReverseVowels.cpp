#include <algorithm>
#include <iostream>
#include <string>

class Solution
{
  public:
    std::string reverseVowels(std::string s)
    {
        bool getOut{false};
        std::size_t initJ{s.size() - 1};
        for (std::size_t i{0}; i < s.size(); i++)
        {
            getOut = false;
            switch (s.at(i))
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':

                for (std::size_t j{initJ}; j > i; j--)
                {
                    switch (s.at(j))
                    {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                    case 'A':
                    case 'E':
                    case 'I':
                    case 'O':
                    case 'U':

                        std::swap(s.at(i), s.at(j));
                        getOut = true;
                        initJ = j - 1;
                        break;
                    }
                    if (getOut)
                    {
                        break;
                    }
                }
                break;
            }
        }
        return s;
    }
};

int main()
{
    Solution sol{};
    std::cout << sol.reverseVowels("hello") << '\n';
    std::cout << sol.reverseVowels("leetcode") << '\n';
    std::cout << sol.reverseVowels("race car") << '\n';
}