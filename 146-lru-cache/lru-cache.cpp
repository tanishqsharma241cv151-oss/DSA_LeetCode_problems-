class LRUCache {
public:
    class Node{
    public:
        int key,val;
        Node* next;
        Node* prev;
        Node(int k,int v){ //construtor
            key=k;
            val=v;
            next=nullptr;
            prev=nullptr;
        }
    };
    LRUCache(int capacity) {
        //initialise everyhting
        head->next=tail;
        tail->prev=head;
        cap=capacity;
        mpp.clear();
    }
    void insertafterhead(Node* node){
        Node* ahead=head->next;
        ahead->prev=node;
        node->next=ahead;
        head->next=node;
        node->prev=head;  
    }
    void deletenode(Node* node){ //this doesnt actually delete the node just removes it from the link chain.
        Node* back=node->prev;
        Node* front=node->next;
        back->next=front;
        front->prev=back;
    }
    int cap;
    unordered_map<int,Node*>mpp;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            deletenode(mpp[key]); 
            insertafterhead(mpp[key]);
            return mpp[key]->val;
        }
        else return -1;
    }
    void put(int key, int value) {
        if(cap==0) return;
        if(mpp.find(key)!=mpp.end()){ //replace its value.
            mpp[key]->val=value;
            deletenode(mpp[key]);
            insertafterhead(mpp[key]);
        }
        else{
            if(mpp.size()==cap){
                //capacity is full remove the lru element behind tail.
                Node* node=tail->prev;
                mpp.erase(node->key);
                deletenode(node);
            }
            Node* node=new Node(key,value);
            insertafterhead(node);
            mpp[key]=node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */