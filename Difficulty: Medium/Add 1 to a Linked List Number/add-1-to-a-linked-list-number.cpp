/* Structure of linked list Node
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
    Node* reverse(Node* head){
        Node* prev=nullptr;
        Node* temp=head;
        while(temp!=nullptr){
            Node* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        if(head==nullptr)  return nullptr;
        int carry=1;
        head=reverse(head);
        Node* temp=head;
        while(carry!=0 && temp!=nullptr){
            if((temp->data)+1==10){
                temp->data=0;
                carry=1;
            }
            else{
                temp->data=(temp->data)+1;
                carry=0;
                break;
            }
            temp=temp->next;
        }
        head=reverse(head);
        if(carry==1){
            Node* newhead=new Node(1);
            newhead->next=head;
            head=newhead;
        }
        return head;
    }
};