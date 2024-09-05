#include <iostream>
#include <stack>

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
    bool isPalindrome([[maybe_unused]] ListNode *head)
    {
        std::stack<int> st;
        ListNode *headForIter2{head};
        while (head)
        {
            st.push(head->val);
            head = head->next;
        }

        while (headForIter2)
        {
            if (headForIter2->val == st.top())
            {
                st.pop();
            }
            headForIter2 = headForIter2->next;
        }

        return st.empty();
    }
};

void printList(ListNode *head)
{
    while (head)
    {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "NULL\n";
}

int main()
{
    Solution sol;
    // 1,2,2,3,2,2,1
    ListNode *list{new ListNode{
      1, new ListNode{2, new ListNode{2, new ListNode{3, new ListNode{2, new ListNode{2, new ListNode{1}}}}}}}};

    printList(list);

    std::cout << sol.isPalindrome(list) << '\n';

    return 0;
}
