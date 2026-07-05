/* Node Structure
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        Node dummy(0);
        dummy.next=head;
        Node* fast=&dummy;
        Node* slow=head;
        for(int i=0;i<k;i++){
            fast=fast->next;
            if(fast==nullptr){
                return -1;
            }
        }
        
        while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        
        return slow->data;
    }
};