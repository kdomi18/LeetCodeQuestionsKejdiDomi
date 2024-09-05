#include <iostream>
#include <vector>

class Solution
{

  private:
    int contribution(std::vector<int>::size_type i, std::vector<int>::size_type j, std::vector<int>::size_type h,
                     std::vector<int>::size_type w, std::vector<std::vector<int>> &grid)
    {
        int l{1}, r{1}, u{1}, d{1};
        int c{};

        // l
        if (i == 0)
        {
            c += u;
        }
        else
        {
            if (grid[i - 1][j] != 1)
            {
                c += u;
            }
        }

        // r
        if (i + 1 >= h)
        {
            c += d;
        }
        else
        {
            if (grid[i + 1][j] != 1)
            {
                c += d;
            }
        }

        // u
        if (j == 0)
        {
            c += l;
        }
        else
        {
            if (grid[i][j - 1] != 1)
            {
                c += l;
            }
        }

        // d
        if (j + 1 >= w)
        {
            c += r;
        }
        else
        {
            if (grid[i][j + 1] != 1)
            {
                c += r;
            }
        }
        return c;
    }

  public:
    int islandPerimeter(std::vector<std::vector<int>> &grid)
    {
        if (grid.empty())
        {
            return 0;
        }

        std::vector<int>::size_type h{grid.size()};
        std::vector<int>::size_type w{grid.at(0).size()};

        int rSum{};
        for (std::size_t i{}; i < h; i++)
        {
            for (std::size_t j{}; j < w; j++)
            {
                if (grid.at(i).at(j) == 1)
                {
                    // std::cout << i << j << '\n';
                    // std::cout << contribution(i, j, h, w, grid) << '\n';
                    rSum += contribution(i, j, h, w, grid);
                }
            }
        }
        return rSum;
    }
};

int main()
{
    Solution sol{};
    std::vector<std::vector<int>> grid{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};

    std::cout << sol.islandPerimeter(grid);

    return 0;
}