class MyQueue
{
public:
    stack<int> stack1;
    stack<int> stack2;

    MyQueue()
    {
    }

    void push(int x)
    {
        stack1.push(x);
    }

    int pop()
    {
        int ret = 0;
        if (!stack2.empty())
        {
            ret = stack2.top();
            stack2.pop();
            return ret;
        }
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        // if(!stack2.empty()) {
        ret = stack2.top();
        stack2.pop();
        return ret;
        //}
    }

    int peek()
    {
        if (!stack2.empty())
        {
            return stack2.top();
        }
        while (!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        // if(!stack2.empty()) {
        return stack2.top();
    }

    bool empty()
    {
        return stack1.empty() && stack2.empty();
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