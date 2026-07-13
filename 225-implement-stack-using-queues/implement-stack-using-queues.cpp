class MyStack {
public:
    queue<int>q;
    int size;
    MyStack() {
        size=0;
        
    }
    
    void push(int x) {
        if(q.empty()){
            q.push(x);
        }
        else{
            q.push(x);
            int s=q.size();
            for(int i=1;i<=s-1;i++){
                q.push(q.front());
                q.pop();
            } 
        } 
    }
    
    int pop() {
        int el=q.front();
        q.pop();
        return el;
    }
    
    int top() {
        return q.front();
        
    }
    
    bool empty() {
        if(q.empty())return true;
        else return false;
        
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