#include <vector>

class Solution
{
  public:
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        int index{static_cast<int>(digits.size()) - 1};

        while (true)
        {
            if (index < 0)
            {
                digits.insert(digits.begin(), 1);
                return digits;
            }

            size_t c_index = static_cast<size_t>(index);

            if (digits[c_index] != 9)
            {
                digits[c_index]++;
                return digits;
            }
            else
            {
                digits[c_index] = 0;
                index--;
            }
        }

        return digits;
    }
};