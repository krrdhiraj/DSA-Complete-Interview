class MyStack {
public:
    queue<int> q;
    int t = -1;
    MyStack() {
       
    }
    
    void push(int x) {
        t++;
        q.push(x);
    }
    
    int pop() {
        int temp = -1;
        queue<int> que;
        if(!q.empty()){
            while(q.size() > 1){
                que.push(q.front());
                q.pop();
            }
            temp = q.back();
            q = que;
        }
        return temp;
    }
    
    int top() {
        int back = -1;
        if(!q.empty()){
            back = q.back();
        }
        return back;
    }
    
    bool empty() {
        return q.empty();
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