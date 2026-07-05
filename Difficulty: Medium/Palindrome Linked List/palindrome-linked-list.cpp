/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = nullptr;
    }
};*/

class Solution {
  public:
    Node* reverse(Node* temp){
        Node* last=nullptr;
        while(temp!=nullptr){
            Node* front=temp->next;
            temp->next=last;
            last=temp;
            temp=front;
        }
        return last;
    }
    bool isPalindrome(Node *head) {
        //first find the m1 node.
        Node*slow=head;
        Node*fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* newhead=reverse(slow->next);
        slow->next=newhead;
        Node* first=head;
        Node* second=newhead;
        while(second!=nullptr){
            if(first->data==second->data){ //compare data not pointers.
                first=first->next;
                second=second->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
};