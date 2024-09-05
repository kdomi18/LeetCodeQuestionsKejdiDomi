#include <iostream>
#include <string>

class Solution
{
  private:
    bool check(std::string &word, int mode)
    {
        // first and second (F and S) chars determine the mode where upper means 0 and lower means 1
        // for example: word = FSspan has mode 0 because F is upper(0) and S is upper(0) and (00) in bin = 0 in dec
        // mode : 0->FS, 1->Fs, 3->fs
        switch (mode)
        {
        case 0:
            for (std::size_t i{2}; i < word.size(); i++)
            {
                if (islower(word.at(i)))
                {
                    return false;
                }
            }
            return true;

            break;
        case 1:
            for (std::size_t i{2}; i < word.size(); i++)
            {
                if (isupper(word.at(i)))
                {
                    return false;
                }
            }
            return true;
            break;
        case 3:
            for (std::size_t i{2}; i < word.size(); i++)
            {
                if (isupper(word.at(i)))
                {
                    return false;
                }
            }
            return true;
            break;

            default:
            return 0;
        }
    }

  public:
    bool detectCapitalUse(std::string word)
    {
        if (word.size() == 1)
        {
            return true;
        }
        
        if (word.size() < 3)
        {
            return !(isupper(word.at(1)) && islower(word.at(0)));
        }
        else
        {
            if (isupper(word.at(0)) && isupper(word.at(1)))
            {
                return check(word, 0);
            }
            if (isupper(word.at(0)) && islower(word.at(1)))
            {
                return check(word, 1);
            }
            if (islower(word.at(0)) && isupper(word.at(1)))
            {
                return false;
            }
            if (islower(word.at(0)) && islower(word.at(1)))
            {
                return check(word, 3);
            }
        }
        return false;
    }
};

int main()
{
    Solution sol{};
    std::cout << std::boolalpha;

    std::cout << sol.detectCapitalUse("USA") << '\n';   // true
    std::cout << sol.detectCapitalUse("FlaG") << '\n';  // false
    std::cout << sol.detectCapitalUse("hello") << '\n'; // true

    return 0;
}