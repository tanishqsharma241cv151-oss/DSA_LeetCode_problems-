class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
    Node* start;
    Node* end;
    int size1;
  public:
    myQueue() {
        // Initialize your data members
        start=end=nullptr;
        size1=0;
    }

    bool isEmpty() {
        // check if the queue is empty
        if(size1==0)return true;
        else return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        if(size1==0){
            Node* newnode=new Node(x);
            start=end=newnode;
            size1++;
        }
        else{
            Node* newnode=new Node(x);
            end->next=newnode;
            end=newnode;
            size1++;
        }
    }

    void dequeue() {
        // Removes the front element of the queue
        if(size1==0){ }
        else if(size1==1){
            Node* temp=start;
            start=end=nullptr;
            delete temp;
            temp=nullptr;
            size1--;
        }
        else{
            Node* temp=start;
            start=start->next;
            delete temp;
            temp=nullptr;
            size1--;
        }
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(size1!=0){
            return start->data;
        }
        else return -1;
    }

    int size() {
        // Returns the current size of the queue.
        return size1;
    }
};
