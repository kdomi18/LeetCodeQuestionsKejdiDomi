#include <iostream>
#include <string>
#include <vector>

template <typename T>
[[maybe_unused]] auto print = [](std::vector<T> vec) {
    for (auto &&i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
};

class Solution
{
  private:
    bool wordCanBeWritten(std::string &word, std::string &row)
    {
        for (std::size_t i{}; i < word.size(); i++)
        {
            if (row.find(std::tolower(word.at(i))) == row.npos)
                return false;
        }
        return true;
    }

  public:
    std::vector<std::string> findWords(std::vector<std::string> &words)
    {
        std::string first{"qwertyuiop"}, second{"asdfghjkl"}, third{"zxcvbnm"};
        std::vector<std::string> retVec{};
        for (auto &&word : words)
        {
            if (wordCanBeWritten(word, first) || wordCanBeWritten(word, second) || wordCanBeWritten(word, third))
            {
                retVec.emplace_back(word);
            }
        }
        return retVec;
    }
};

int main()
{
    Solution sol{};
    std::vector<std::string> words{"Hello", "Alaska", "Dad", "Peace"};
    print<std::string>(sol.findWords(words));

    return 0;
}