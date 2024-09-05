#include <iostream>
#include <string>

class Solution
{
  private:
    void reverseOnlyHalf(std::string &s, std::size_t sIndex, int k)
    {
        for (std::size_t i{0}; i < static_cast<std::size_t>(k / 2); i++)
        {
            std::swap(s.at(sIndex + i), s.at(sIndex + static_cast<std::size_t>(k - 1) - i));
        }
    }

    void reverseAll(std::string &s, std::size_t sIndex, std::size_t lastIndex)
    {
        while (sIndex < lastIndex)
        {
            std::swap(s.at(sIndex), s.at(lastIndex));
            ++sIndex;
            --lastIndex;
        }
    }

  public:
    std::string reverseStr(std::string s, int k)
    {
        if (static_cast<std::size_t>(k) > s.size())
        {
            reverseAll(s, 0, s.size() - 1);
            return s;
        }
        std::size_t sIndex{}, fIndex{};
        for (std::size_t i{}; i < s.size(); i += static_cast<std::size_t>(2 * k))
        {
            sIndex = i;
            fIndex = i + static_cast<std::size_t>(2 * k - 1);
            if (fIndex < s.size())
            {
                reverseOnlyHalf(s, sIndex, k);
            }
            else if (fIndex - static_cast<std::size_t>(k) < s.size())
            {
                reverseOnlyHalf(s, sIndex, k);
            }
            else
            {
                reverseAll(s, sIndex, s.size() - 1);
            }
        }
        return s;
    }
};

int main()
{
    Solution sol{};
    std::cout << sol.reverseStr("abcdefg", 8) << '\n';
    std::cout << sol.reverseStr("abcd", 2) << '\n';
    return 0;
}
