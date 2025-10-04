class MinStack {
public:
    stack<long> st;
    long minEl ;
    MinStack() {
        minEl = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            minEl = val;
        }else{
            if(val > minEl){
                st.push(val);
            }else{
                st.push((long)2*val - minEl);
                minEl = val;
            }
        }
    }
    
    void pop() {
       if(st.empty()){
            return ;
       }
       if(st.top() > minEl)
            st.pop();
        else{
            minEl = 2*minEl - st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.empty())
            return -1;
        if(st.top() > minEl)
            return st.top();
        return minEl;
    }
    
    int getMin() {
        if(st.empty())
            return -1;
        return minEl;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */