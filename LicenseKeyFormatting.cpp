#include <iostream>
#include <string>

class Solution
{
  public:
    std::string licenseKeyFormatting(std::string s, int k)
    {
        std::string unSplit{};
        for (auto &&i : s)
        {
            if (i == '-')
            {
                continue;
            }
            else if (i >= 'a' && i <= 'z')
            {
                unSplit += std::toupper(i);
            }
            else
            {
                unSplit += i;
            }
        }
        if (unSplit.empty())
        {
            return unSplit;
        }

        int lenOfFirstSplit{static_cast<int>(unSplit.size()) % k};
        if (lenOfFirstSplit == 0)
        {
            lenOfFirstSplit = k;
        }
        int index{0};
        bool first{true};
        while (index < static_cast<int>(unSplit.size()))
        {
            if (first)
            {
                index = lenOfFirstSplit;
                first = false;
            }
            unSplit.insert(unSplit.begin() + index, '-');
            index += k + 1;
        }
        if (unSplit.back() == '-')
        {
            unSplit.pop_back();
        }

        return unSplit;
    }
};

int main()
{
    Solution sol{};

    std::cout << sol.licenseKeyFormatting("5F3Z-2e-9-w", 4) << '\n';
    std::cout << sol.licenseKeyFormatting("2-5g-3-J", 2) << '\n';

    return 0;
}