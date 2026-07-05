/* The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
};
*/

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
        if(head==nullptr) return {nullptr,nullptr};
        int n=2;
        Node* temp=head->next;
        while(temp->next!=head){
            n++;
            temp=temp->next;
        }
        int size=(n+1)/2;
        Node* curr=head;
        
        while(size>1){
            size--;
            curr=curr->next;
        }
        Node* head2=curr->next;
        Node* head1=head;
        curr->next=head;
        temp->next=head2;
        return{head1,head2};
    }
};