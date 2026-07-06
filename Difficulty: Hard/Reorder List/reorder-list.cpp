/* Node Structure
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    Node* reverse(Node* head){
        Node* curr=head;
        Node* prev=nullptr;
        while(curr!=nullptr){
            Node* front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    void reorderList(Node* head) {
        Node* fast=head;
        Node* slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        Node* newhead=reverse(slow->next);
        slow->next=nullptr;
        Node* first=head;
        Node* second=newhead;
        while(second!=nullptr){
            Node* front1=first->next;
            Node* front2=second->next;
            first->next=second;
            second->next=front1;
            first=front1;
            second=front2;
        }
        
    }
};