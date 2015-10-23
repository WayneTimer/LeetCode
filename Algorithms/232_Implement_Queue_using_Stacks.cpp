/*
Time: N/A
Space: O(2n) = O(n)
Runtime: 0ms

by Timer [linyicx@126.com]
2015.10.23
*/
class Queue
{
private:
    stack<int> *in,*out;
    
    void maintain()
    {
        if (out->empty())
        {
            while (!in->empty())
            {
                out->push(in->top());
                in->pop();
            }
        }
    }
    
public:
    Queue()
    {
        in = new stack<int>();
        out = new stack<int>();
    }
    
    // Push element x to the back of queue.
    void push(int x)
    {
        in->push(x);
    }

    // Removes the element from in front of queue.
    void pop(void)
    {
        maintain();
        out->pop();
    }

    // Get the front element.
    int peek(void)
    {
        maintain();
        return out->top();
    }

    // Return whether the queue is empty.
    bool empty(void)
    {
        return (in->empty() && out->empty());
    }
};
