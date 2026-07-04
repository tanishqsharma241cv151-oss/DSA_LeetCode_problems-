/*
class Node {
 public:
    int data ;
    Node *next ;

    Node(int x) {
        data = x ;
        next = nullptr ;
    }
};
*/

class Solution {
  public:
    Node* reverseList(Node* head) {
        Node* curr=head;
        Node* last=nullptr;
        while(curr!=nullptr){
            Node* temp=curr->next;
            curr->next=last;
            last=curr;
            curr=temp;
        }
        return last;
        
    }
};