#include <iostream>
#include <string>

class Solution
{
  public:
    int strStr(std::string haystack, std::string needle)
    {
        if (haystack.size() < needle.size())
            return -1;
        if (haystack == needle)
            return 0;

        int i{0};
        while (haystack.size() - i >= needle.size())
        {
            if (haystack[i] == needle[0])
            {
                if (needle.size() == 1)
                {
                    return i;
                }

                for (int j{1}; j < needle.size(); j++)
                {
                    if (haystack[i + j] == needle[j])
                    {
                        if (j == needle.size() - 1)
                        {
                            return i;
                        }
                        else
                        {
                            continue;
                        }
                    }
                    else
                    {
                        i++;
                        break;
                    }
                }
            }
            else
            {
                i++;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    std::string haystack{"abc"};
    std::string needle{"c"};

    std::cout << sol.strStr(haystack, needle) << '\n';

    return 0;
}