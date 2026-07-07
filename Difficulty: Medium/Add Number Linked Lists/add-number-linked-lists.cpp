/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node* reverse(Node* head1){
        Node* prev=nullptr;
        Node* temp=head1;
        while(temp!=nullptr){
            Node* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    Node* addTwoLists(Node* head1, Node* head2) {
        Node dummy(0);
        Node* temp=&dummy;
        head1=reverse(head1);
        head2=reverse(head2);
        int carry=0;
        while(head1!=nullptr || head2!=nullptr || carry!=0){
            int sum=0;
            if(head1!=nullptr){
                sum+=head1->data;
                head1=head1->next;
            }
            if(head2!=nullptr){
                sum+=head2->data;
                head2=head2->next;
            }
            sum+=carry;
            carry=sum/10;
            Node* newnode=new Node(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        Node* newhead=reverse(dummy.next);
        while(newhead->next!=nullptr && newhead->data==0){
            Node* curr=newhead;
            newhead=newhead->next;
            delete curr;
            curr->next=nullptr;
        }
        return newhead;
       
    }
};