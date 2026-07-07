/* a Node of the doubly linked list
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};
*/

class Solution {
  public:

    // Function to delete a specified node from the linked list
    Node* deleteAllOccurOfX(Node* head, int x) {
        Node* temp=head;
        
        while(temp!=nullptr){
            Node*curr=temp;
            Node*back=curr->prev;
            Node*front=curr->next;
            temp=front;
            if(curr->data==x){
                if(curr->prev==nullptr){//curr is at head;
                    front->prev=back;
                    head=front;
                }
                else if(curr->next==nullptr){//curr is at tail;
                    back->next=front;
                }
                else if(curr->prev!=nullptr && curr->next!=nullptr){
                    front->prev=back;
                    back->next=front;
                }
                delete curr;
            }
            temp=front;
        }
        return head;
        
    }
};