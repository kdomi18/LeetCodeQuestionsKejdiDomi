#include <iostream>
#include <vector>

class Solution
{
  public:
    int findPoisonedDuration(std::vector<int> &timeSeries, int duration)
    {
        int ret{duration};
        for (std::size_t i{0}; i < timeSeries.size()-1; i++)
        {
            int f{timeSeries.at(i)}, s{timeSeries.at(i+1)};
            ret+= std::min(s-f, duration);
        }
        return ret;
    }
};

int main()
{
    Solution sol{};

    std::vector<int> tS1{1,4};
    std::cout << sol.findPoisonedDuration(tS1, 2) << '\n';

    std::vector<int> tS2{1,2,3,4,5,6};
    std::cout << sol.findPoisonedDuration(tS2, 2) << '\n';

    std::vector<int> tS3{1,2};
    std::cout << sol.findPoisonedDuration(tS3, 2) << '\n';

    return 0;
}