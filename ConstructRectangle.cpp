#include <cmath>
#include <iostream>
#include <vector>

[[maybe_unused]] auto print = [](std::vector<int> vec) {
    for (auto &&i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
};

class Solution
{
  public:
    std::vector<int> constructRectangle(int area)
    {
        int ideal{static_cast<int>(std::sqrt(area))};
        int s{};
        while (true)
        {
            if (area % ideal == 0)
            {
                s = area / ideal;
                if (s > ideal)
                {
                    std::swap(s, ideal);
                }

                return {ideal, s};
            }
            else
            {
                ideal++;
            }
        }
    }
};

int main()
{
    Solution sol{};

    print(sol.constructRectangle(4));
    print(sol.constructRectangle(3));
    print(sol.constructRectangle(37));
    print(sol.constructRectangle(8));
    print(sol.constructRectangle(16));
}