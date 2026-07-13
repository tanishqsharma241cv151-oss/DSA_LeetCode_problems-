/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class myStack {
    Node* top;
    int size1;

  public:
    myStack() {
        // Initialize your data members
        top=nullptr;
        size1=0;
        
    }

    bool isEmpty() {
        // check if the stack is empty
        if(size1==0)return true;
        else return false;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node* newnode= new Node(x);
        newnode->next=top;
        top=newnode;
        size1+=1;
    }

    void pop() {
        // Removes the top element of the stack
        if(top!=nullptr){
            Node* temp=top;
            top=top->next;
            delete temp;
            temp=nullptr;
            size1-=1;
        }
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(size1==0) return -1;
        else return top->data;
    }

    int size() {
        // Returns the current size of the stack.
        return size1;
    }
};