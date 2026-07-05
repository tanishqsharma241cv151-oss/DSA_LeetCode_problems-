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
    Node* deleteMid(Node* head) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        Node* fast=head;
        Node*slow=head;
        Node*prev=nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=slow->next;
        delete slow;
        slow=nullptr;
        return head;
        
    }
};