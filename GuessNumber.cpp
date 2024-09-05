/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

#include <iostream>

int guess(int num)
{
    if (num < 10)
    {
        return 1;
    }
    if (num > 10)
    {
        return -1;
    }
    if (num == 10)
    {
        return 0;
    }
};

class Solution
{
  public:
    int guessNumber(int n)
    {
        int l{1};
        int r{n};
        int mid{l + (r - l) / 2};
        int g{};

        while (r >= l && r - l > 1)
        {
            g = guess(mid);
            if (g == 0)
            {
                return mid;
            }
            if (g == -1)
            {
                r = mid - 1;
                
            }
            if (g == 1)
            {
                l = mid + 1;
            }
            mid = l + (r - l) / 2;
        }
        if (guess(r) == 0)
        {
            return r;
        }
        else
        {
            return l;
        }
        return -1;
    }
};

int main()
{
    Solution sol{};
    std::cout << sol.guessNumber(13);
    std::cout << sol.guessNumber(14);

    return 0;
}
