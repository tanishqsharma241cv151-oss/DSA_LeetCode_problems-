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
            Node*back=temp->prev;
            Node*front=temp->next;
            if(temp->data==x){
                if(back==nullptr){
                    if(front==nullptr){ //single node list.
                        delete temp;
                        return nullptr;
                    }
                    else{ //temp is at head.
                        front->prev=back;
                        head=front;
                    }
                }
                else if(front==nullptr){//temp is at tail.
                    back->next=front;
                }
                else{
                    front->prev=back;
                    back->next=front;
                }
                delete temp;
            }
            temp=front;
        }
        return head;
        
    }
};