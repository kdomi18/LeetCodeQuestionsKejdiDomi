#include <iostream>
#include <vector>

auto print = [](std::vector<int> vec) {
    for (auto &&i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
};

class Solution
{
  public:
    void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
    {
        if (n == 0)
        {
            return;
        }

        if (m == 0)
        {
            nums1 = nums2;
            return;
        }

        for (int index = 0; index < n; index++)
        {
            insertOne(nums2[index], nums1, m);
            m++;
        }
    }

  private:
    void insertOne(int &x, std::vector<int> &nums1, int sizeOfNums)
    {
        int temp{};

        // figure out the index where to add it
        while (nums1.at(sizeOfNums - 1) > x)
        {
            temp = nums1.at(sizeOfNums - 1);
            nums1.at(sizeOfNums - 1) = nums1.at(sizeOfNums);
            nums1.at(sizeOfNums) = temp;
            sizeOfNums--;
            if (sizeOfNums - 1 < 0)
            {
                break;
            }
        }

        if (sizeOfNums >= 0)
        {
            nums1.at(sizeOfNums) = x;
        }
    }
};

int main()
{
    Solution sol;
    std::vector<int> n1{2, 0};
    std::vector<int> n2{1};
    int m{1};
    int n{1};

    std::cout << "nums1: ";
    print(n1);
    std::cout << "nums2: ";
    print(n2);

    sol.merge(n1, m, n2, n);

    std::cout << "nums1 after: ";
    print(n1);
    std::cout << "nums2 after: ";
    print(n2);

    return 0;
}