#include <iostream>
#include <vector>

class Solution
{
  public:
    int climbStairs(long int n)
    {
        std::vector<int> fib(2);
        fib[0] = 1;
        fib[1] = 1;
        long int i{0};
        long int fib_one{};
        while (true)
        {
            fib_one = fib[1];
            fib[1] = (fib[0] + fib[1]);
            fib[0] = fib_one;     
            i++;
            if(i == n) break;
        }
        return fib[0];
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[])
{
    Solution sol;
    std::cout << sol.climbStairs(2) << '\n';
    std::cout << sol.climbStairs(3) << '\n';
    std::cout << sol.climbStairs(4) << '\n';
    std::cout << sol.climbStairs(45) << '\n';
    return 0;
}
