/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {
        if(headRef==nullptr || headRef->next==nullptr)return headRef;
        Node* temp=headRef;
        while(temp!=nullptr && temp->next!=nullptr){
            Node* nextnode=temp->next;
            while(nextnode!=nullptr && temp->data==nextnode->data){
                Node* curr=nextnode;
                nextnode=nextnode->next;
                delete curr;
                curr=nullptr;
            }
            temp->next=nextnode;
            if(nextnode!=nullptr){
                nextnode->prev=temp;
            }
            temp=temp->next;
            
        }
        return headRef;
    }
};