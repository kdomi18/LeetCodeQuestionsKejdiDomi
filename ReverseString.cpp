#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        std::ranges::reverse(s);
    }
};