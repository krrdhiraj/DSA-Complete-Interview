class MyQueue {
public:
    stack<int> st;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        int top = -1;
        if(!st.empty()){
            stack<int> temp;
            while(!st.empty()){
                temp.push(st.top());
                st.pop();
            }
            top = temp.top();
            temp.pop();
            while(!temp.empty()){
                st.push(temp.top());
                temp.pop();
            }
        }
        return top;
    }
    
    int peek() {
        int top = -1;
        if(!st.empty()){
            stack<int> temp;
            while(!st.empty()){
                temp.push(st.top());
                st.pop();
            }
            top = temp.top();
            while(!temp.empty()){
                st.push(temp.top());
                temp.pop();
            }
        }
        return top;
    }
    
    bool empty() {
        return st.empty();
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