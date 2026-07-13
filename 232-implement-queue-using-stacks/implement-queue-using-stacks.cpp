class MyQueue {
public:
    stack<int>st1,st2;
    MyQueue() {
        //follow 3 steps;
        //1.push everyhting in s1;
        //2.put all elements from s1 to s2 if s2 is empty;
        //3.push any new elements in s1;
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(!st2.empty()){
            int el=st2.top();
            st2.pop();
            return el;
        }
        else{
            while(st1.size()){
                st2.push(st1.top());
                st1.pop();
            }
            int el=st2.top();
            st2.pop();
            return el;
        }
    }
    
    int peek() {
        if(!st2.empty()){
            return st2.top();
        }
        else{
            while(st1.size()){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
        
        
    }
    
    bool empty() {
        if(st1.size()==0 && st2.size()==0)return true;
        else return false;
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