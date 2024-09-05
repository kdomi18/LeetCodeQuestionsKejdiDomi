#include <cstddef>
#include <iostream>
#include <stack>

class MyQueue
{
  public:
    MyQueue()
    {
    }

    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        int ret{};
        transfer(s1, s2, s1.size());
        ret = s2.top();
        s2.pop();
        transfer(s2, s1, s2.size());
        return ret;
    }

    int peek()
    {
        int ret{};
        transfer(s1, s2, s1.size());
        ret = s2.top();
        transfer(s2, s1, s2.size());
        return ret;
    }

    bool empty()
    {
        return s1.empty();
    }

  private:
    std::stack<int> s1{};
    std::stack<int> s2{};
    void transfer(std::stack<int> &source, std::stack<int> &target, size_t size)
    {

        if (size > source.size())
        {
            size = source.size();
        }

        size_t SIZE{source.size()};

        while (source.size() != (SIZE - size))
        {
            target.push(source.top());
            source.pop();
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{
    MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    std::cout << obj->peek() << '\n';
    std::cout << obj->empty() << '\n';

    return 0;
}
