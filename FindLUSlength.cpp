#include <iostream>
#include <string>

class Solution
{
  public:
    int findLUSlength(std::string a, std::string b)
    {
        if (a.compare(b) == 0)
        {
            return -1;
        }
        else
        {
            return a.size() > b.size() ? static_cast<int>(a.size()) : static_cast<int>(b.size());
        }
    }
};

int main()
{
    Solution sol{};
    std::cout << sol.findLUSlength("aba", "cdcs");
    return 0;
}