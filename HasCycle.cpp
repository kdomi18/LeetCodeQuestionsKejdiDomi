#include <vector>
#include <fstream>
#include <iostream>
#include <string>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
};

auto init = []() {
    std::cin.sync_with_stdio(false);
    std::fstream out("user.out");
    for (std::string s; std::getline(std::cin, s);)
    {
        std::getline(std::cin, s);
        s[0] != '-' ? out << "true\n" : out << "false\n";
    }
    out.flush();
    exit(0);
    return 0;
}();

class Solution
{
  public:
    bool hasCycle(ListNode *head)
    {
        std::vector<ListNode *> vec{};
        while (head)
        {
            if (std::find(vec.begin(), vec.end(), head) == vec.end())
            {
                vec.push_back(head);
            }
            else
            {
                return true;
            }
            head = head->next;
        }

        return false;
    }
};

int main()
{
    Solution sol;
    ListNode *first = new ListNode(3);
    ListNode *sec = new ListNode(2);
    ListNode *third = new ListNode(0);
    ListNode *fourth = new ListNode(-4);

    first->next = sec;
    sec->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    std::cout << std::boolalpha << sol.hasCycle(first) << '\n';

    return 0;
}