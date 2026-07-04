/* Structure of doubly linked list node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        Node dummy(0);
        dummy.next=head;
        Node* last=&dummy;
        Node* curr= head;
        while(curr!=nullptr){
            last=curr->prev;
            curr->prev=curr->next;
            curr->next=last;
            last=curr;
            curr=curr->prev;
        }
        return last;
    }
};