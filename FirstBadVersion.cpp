// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#include <iostream>

bool isBadVersion(int version)
{
    if (version >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

class Solution
{

  public:
    int firstBadVersion(int n)
    {
        
        if (isBadVersion(n / 2))
        {
            return binSearch(1, n / 2, false);
        }
        else
        {
            return binSearch(n / 2 + 1, n, true);
        }
    }

    int binSearch(int first, int last, bool lookingFor)
    {
        if (first == last)
        {
            return first;
        }
        
        int mid{first/2 + last/2};
        if (isBadVersion(mid) == lookingFor)
        {
            return walk(mid, lookingFor);
        }
        else
        {
            if (!lookingFor)
            {
                return binSearch(first, mid, lookingFor);
            }
            else
            {
                return binSearch(mid + 1, last, lookingFor);
            }
        }
    }

    int walk(int start, bool direction)
    {
        if (direction == false)
        {
            if (isBadVersion(start))
            {
                return start;
            }
            else
            {
                return walk(start + 1, direction);
            }
        }
        else
        {
            if (!isBadVersion(start))
            {
                return start + 1;
            }
            else
            {
                return walk(start - 1, direction);
            }
        }
    }
};

int main()
{
    Solution sol{};
    std::cout << sol.firstBadVersion(2) << '\n';
    std::cout << sol.firstBadVersion(15) << '\n';
    
}

// 1b,2b
//
//