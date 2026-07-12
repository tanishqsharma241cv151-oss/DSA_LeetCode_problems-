class myStack {
  public:
    int* st;
    int capacity;
    int top;
    myStack(int n) {
        // Define Data Structures
        capacity=n;
        top=-1;
        st=new int[n];
    }

    bool isEmpty() {
        // check if the stack is empty
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull() {
        // check if the stack is full
        if(top==capacity-1) return true;
        else return false;
    }

    void push(int x) {
        // inserts x at the top of the stack
        if(top!=capacity-1){
            top+=1;
            st[top]=x;
        }
        
    }

    void pop() {
        // removes an element from the top of the stack
        if(top!=-1){
            top-=1;
        }
    }

    int peek() {
        // Returns the top element of the stack
        if(top!=-1){
            return st[top];
        }
        else return -1;
        
    }
};