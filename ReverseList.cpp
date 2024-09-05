#include <iostream>
//  Definition for singly-linked list.

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
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
        {
            return head;
        }
        ListNode *r{head};
        ListNode *tail{nullptr};
        while (head)
        {
            head = head->next;
            r->next = tail;
            tail = r;
            r = head;
        }
        return tail;
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
    ListNode *head{new ListNode{1, new ListNode{2, new ListNode{3}}}};
    printList(head);
    printList(sol.reverseList(head));

    return 0;
}
