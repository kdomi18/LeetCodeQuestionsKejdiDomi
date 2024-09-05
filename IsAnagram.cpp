#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
class Solution
{
  public:
    bool isAnagram(std::string s, std::string t)
    {
        for (auto &&ch : s)
        {
            size_t it{t.find(ch)};
            if (it != t.npos)
            {
                t.erase(it, 1);
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
    Solution sol;
    std::cout << sol.isAnagram("angram", "agaram");
    return 0;
}
