#include <iostream>
#include <string_view>

class Solution
{
  public:
    int lengthOfLastWord(std::string_view s)
    {
        if (s.empty())
            return 0;

        // strip the string of right spaces
        while (std::isspace(s.back()))
        {
            s.remove_suffix(1);
        }

        return s.size() - (s.find_last_of(" ")) - 1;
    }
};
