#include <iostream>
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

class Solution
{
  public:
    ListNode *removeElements([[maybe_unused]] ListNode *head, [[maybe_unused]] int val)
    {
        ListNode *ptr{head};
        ListNode *prev{};
        bool changePrev{true};
        while (ptr)
        {
            changePrev = true;
            if (ptr->val == val && ptr != head)
            {
                prev->next = ptr->next;
                changePrev = false;
            }

            if (ptr->val == val && ptr == head)
            {
                head = head->next;
            }
            if (changePrev)
            {
                prev = ptr;
            }
            ptr = ptr->next;
        }
        return head;
    }
};

void printList(ListNode *ptr)
{
    while (ptr)
    {
        std::cout << ptr->val << " -> ";
        ptr = ptr->next;
    }
    std::cout << "NULL\n";
}

int main()
{
    Solution sol;
    ListNode *head{new ListNode{1, new ListNode{2, new ListNode{2, new ListNode{1}}}}};
    ListNode *ptr{head};
    printList(ptr);
    printList(sol.removeElements(head, 2));
}
