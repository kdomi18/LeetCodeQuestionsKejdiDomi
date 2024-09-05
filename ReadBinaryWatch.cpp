#include <bitset>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Solution
{
  private:
    bool bitsetValid(const std::bitset<10> b, std::pair<std::string, std::string> &p)
    {
        auto dummy1{b};
        auto dummy2{b};
        dummy1 >>= 6;
        dummy2 &= 0b00'0011'1111;
        if (dummy1.to_ulong() <= 11)
        {
            if (dummy2.to_ulong() <= 59)
            {
                p.first = std::to_string(static_cast<int>(dummy1.to_ulong()));
                p.second = std::to_string(static_cast<int>(dummy2.to_ulong()));
                return true;
            }
        }

        return false;
    }

    std::string buildStringFromPair(const std::pair<std::string, std::string> &p)
    {
        return p.first + ":" + ((p.second.size() == 1) ? "0" : "") + p.second;
    }

  public:
    std::vector<std::string> readBinaryWatch(int turnedOn)
    {
        std::vector<std::string> retVec{};
        std::bitset<10> oneBitset{};
        std::pair<std::string, std::string> p{};

        for (std::size_t i{0}; i < 1 << 10; i++)
        {
            oneBitset = i;
            if (oneBitset.count() == static_cast<std::size_t>(turnedOn))
            {
                if (bitsetValid(oneBitset, p))
                {
                    retVec.push_back(buildStringFromPair(p));
                }
            }
        }
        return retVec;
    }
};

int main()
{
    Solution sol{};
    for (auto &&i : sol.readBinaryWatch(1))
    {
        std::cout << i << ", ";
    }
    std::cout << '\n';

    for (auto &&i : sol.readBinaryWatch(9))
    {
        std::cout << i << ", ";
    }
    std::cout << '\n';

    return 0;
}