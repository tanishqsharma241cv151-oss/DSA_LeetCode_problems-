/* Structure of a Linked List Node
class Node
{
    int data;
    Node next;
    Node(int d) {
       data = d;
       next = nullptr;
    }
};*/
class Solution {
  public:
    Node* merge(Node*lefthead, Node* righthead){
        Node dummy(0);
        Node* temp=&dummy;
        Node* first=lefthead;
        Node* second=righthead;
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
        if(first) temp->next=first;
        else if(second) temp->next=second;
        return dummy.next;
    }
    Node* findmiddle(Node* head){
        Node* fast=head;
        Node* slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    Node* sortLL(Node* head) {
        if(head==nullptr || head->next==nullptr) return head;
        Node* middle=findmiddle(head);
        Node* lefthead=head;
        Node* righthead=middle->next;
        middle->next=nullptr;
        lefthead=sortLL(lefthead);
        righthead=sortLL(righthead);
        return merge(lefthead,righthead);
    }
};