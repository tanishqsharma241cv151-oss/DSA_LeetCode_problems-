class myQueue {
        int* q;
        int start;
        int end;
        int cap;
        int size;
  public:
    myQueue(int n) {
        // Define Data Structures
        q=new int[n];
        start=-1;
        end=-1;
        cap=n;
        size=0;
    }

    bool isEmpty() {
        // check if the queue is empty
        if(size==0) return true;
        else return false;
    }

    bool isFull() {
        // check if the queue is full
        if(size==cap)return true;
        else return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(size==cap){
        }
        if(size==0){
            start=end=0;
            q[end]=x;
            size++;
        }
        else{
            end=(end+1)%cap;
            q[end]=x;
            size++;
        }
        
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(size==0){
        }
        int el=q[start];
        if(size==1){
            start=end=-1;
            size--;
        }
        else{
            start=(start+1)%cap;
            size--;
        }
    }

    int getFront() {
        // Returns the front element of the queue.
        if(size!=0){
            return q[start];
        }
        else return -1;
        
    }

    int getRear() {
        // Return the last element of queue
        if(size!=0){
            return q[end];
        }
        return -1;
        
    }
};