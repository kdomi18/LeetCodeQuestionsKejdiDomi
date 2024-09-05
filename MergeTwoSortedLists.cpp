#include <iostream>
#include <vector>

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
    ListNode *mergeTwoLists([[maybe_unused]] ListNode *list1, [[maybe_unused]] ListNode *list2)
    {
        ListNode *d1{list1};
        ListNode *d2{list2};
        ListNode *head;

        // create head
        if (d1 && d2)
        {
            if (d1->val <= d2->val)
            {
                head = new ListNode{d1->val};
                d1 = d1->next;
            }
            else
            {
                head = new ListNode{d2->val};
                d2 = d2->next;
            }
        }
        else if (d1)
        {
            head = new ListNode{d1->val};
            d1 = d1->next;
        }
        else if (d2)
        {
            head = new ListNode{d2->val};
            d2 = d2->next;
        }
        else
        {
            return nullptr;
        }

        ListNode *current = head;

        // go through lists using d1 and d2
        while (d1 && d2)
        {
            if (d1->val <= d2->val)
            {
                current->next = new ListNode{d1->val};
                d1 = d1->next;
            }
            else
            {
                current->next = new ListNode{d2->val};
                d2 = d2->next;
            }
            current = current->next;
        }

        if (d1 && !d2)
        {
            current->next = d1;
        }
        else if (d2 && !d1)
        {
            current->next = d2;
        }
        else
        {
            current->next = nullptr;
        }

        return head;
    }
};

void printListNode(ListNode *first)
{
    if (first == nullptr)
    {
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

int main()
{
    Solution sol;
    std::vector<int> arr1{1, 2, 8};
    std::vector<int> arr2{-1, 4};
    [[maybe_unused]] ListNode *list1{vecToListNodePtr(arr1)};
    [[maybe_unused]] ListNode *list2{vecToListNodePtr(arr2)};

    printListNode(list1);
    printListNode(list2);
    printListNode(sol.mergeTwoLists(list1, list2));
    return 0;
}
