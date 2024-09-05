#include <iostream>
#include <string>
#include <vector>

class Solution
{

  private:
    std::string FizzBuzzToString(int i)
    {
        std::string buffer{};
        if (i % 3 == 0)
        {
            buffer += "Fizz";
        }
        if (i % 5 == 0)
        {
            buffer += "Buzz";
        }
        if (buffer.empty())
        {
            buffer += std::to_string(i);
        }

        return buffer;
    }

  public:
    std::vector<std::string> fizzBuzz(int n)
    {
        std::vector<std::string> retVec{};
        for (std::size_t i{1}; i <= n; i++)
        {
            retVec.emplace_back(FizzBuzzToString(i));
        }
        return retVec;
    }
};