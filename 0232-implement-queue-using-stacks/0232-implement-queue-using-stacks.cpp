class MyQueue {
public:
    stack<int> st, temp;
    void reverseToOriginal(){
        while(!temp.empty()){
                st.push(temp.top());
                temp.pop();
            }
    }
    void reverse(){
        while(!st.empty()){
                temp.push(st.top());
                st.pop();
            }
    }
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        int top = -1;
        if(!st.empty()){
            reverse();
            top = temp.top();
            temp.pop();
            reverseToOriginal();
        }
        return top;
    }
    
    int peek() {
        int top = -1;
        if(!st.empty()){
            reverse();
            top = temp.top();;
            reverseToOriginal();
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