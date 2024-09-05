#include <iostream>
#include <string>

class Solution
{
  public:
    int countSegments(std::string s)
    {
        if (s.empty())
            return 0;

        int nOfSegments{1};
        for (std::size_t i{0}; i < s.size(); i++)
        {
            if (i + 1 <= s.size() - 1)
            {
                if (s.at(i) != ' ' && s.at(i + 1) == ' ')
                {
                    nOfSegments++;
                }
            }
        }
        if (s.at(s.size() - 1) == ' ')
        {
            nOfSegments--;
        }

        return nOfSegments;
    }
};

int main()
{
    Solution sol{};
    std::cout << sol.countSegments(", , , ,        a, eaefa ") << '\n';
}