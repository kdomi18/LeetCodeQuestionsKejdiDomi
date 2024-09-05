#include <cstddef>
#include <iostream>
#include <queue>

class MyStack
{
  public:
    std::queue<int> q1;
    std::queue<int> q2;

    MyStack()
    {
    }

    void push(int x)
    {
        q1.push(x);
    }

    int pop()
    {
        auto last = q1.back();
        size_t size = q1.size();
        for (size_t i{0}; i < size - 1; i++)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return last;
    }

    int top()
    {
        return q1.back();
    }

    bool empty()
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyStack *obj = new MyStack();
    obj->push(1);

    std::cout << obj->pop() << (obj->empty() ? ", empty" : ", not empty");

    return 0;
}
