/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node dummy(0);
        Node* temp=&dummy;
        Node* first=head1;
        Node* second=head2;
        while(first!=nullptr && second!=nullptr){
            if(first->data<=second->data){
                temp->next=first;
                first=first->next;
            }
            else{
                temp->next=second;
                second=second->next;
            }
            temp=temp->next;
        }
        if(first)temp->next=first;
        else if(second)temp->next=second;
        return dummy.next;
    
        
    }
};