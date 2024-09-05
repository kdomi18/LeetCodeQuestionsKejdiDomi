#include <iostream>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printListNode(ListNode *first)
{
    if (first == nullptr)
    {
        return;
    }
    
    while (true)
    {
        std::cout << first->val << '\n';
        if (first->next == nullptr)
        {
            return;
        }
        first = first->next; // take care: first.next should not be nullptr at this point because we cannot dereference a nullptr.
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
    ListNode *ln1{vecToListNodePtr({})};

    printListNode(ln1);

    ListNode *ln2{vecToListNodePtr({0,0,1,1,2,3,2})};

    printListNode(ln2);

    return 0;
}
