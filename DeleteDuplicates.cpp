#include <iostream>
#include <vector>

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

void printListNode(ListNode *first)
{
    if (first == nullptr)
    {
        std::cout << "null\n";
        return;
    }

    while (true)
    {
        std::cout << first->val << " -> ";
        if (first->next == nullptr)
        {
            std::cout << "null\n";
            return;
        }
        // take care: first.next should not be nullptr at this point because we cannot dereference a nullptr.
        first = first->next;
    }
}

ListNode *vecToListNodePtr(std::vector<int> vec)
{
    ListNode *head{nullptr};

    if (!vec.empty())
    {
        for (int i = vec.size() - 1; i >= 0; i--)
        {
            ListNode *newNode = new ListNode{vec.at(static_cast<size_t>(i)), head};
            head = newNode;
        }
    }
    else
    {
        head = nullptr;
    }

    return head;
}

class Solution
{
  public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }
        
        ListNode *ret = new ListNode(head->val);
        ListNode *realRet = ret;
        while (head)
        {
            if (head->val > ret->val)
            {
                ListNode *tail = new ListNode(head->val);
                ret->next = tail;
                ret = ret->next;
                head = head->next;
            }
            else
            {
                head = head->next;
            }
        }

        return realRet;
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec{1, 1, 1, 2, 2, 4};
    [[maybe_unused]] ListNode *head{vecToListNodePtr(vec)};
    printListNode(head);

    printListNode(sol.deleteDuplicates(head));

    return 0;
}