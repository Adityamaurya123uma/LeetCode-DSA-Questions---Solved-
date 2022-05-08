class MyStack {
public:
    MyStack() {
        
    }
    queue<int> stack;
    
    void push(int x) {
        int n=stack.size();
        stack.push(x);
        for(int i=0;i<n;i++){
            stack.push(stack.front());
            stack.pop();
        }
    }
    
    int pop() {
        int top;
        if(!stack.empty()){
            top=stack.front();
            stack.pop();
            return top;
        }
        return 0;
    }
    
    int top() {
        if(!stack.empty()){
            return stack.front();
        }
        return 0;
    }
    
    bool empty() {132 Pattern
       return stack.empty();
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