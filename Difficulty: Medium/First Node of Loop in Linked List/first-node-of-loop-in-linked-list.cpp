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
    int cycleStart(Node* head) {
        Node* fast=head;
        Node* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=head;
                while(slow!=nullptr){
                    if(slow==fast) return slow->data;
                    slow=slow->next;
                    fast=fast->next;
                }
            }
        }
        return -1;
        
    }
};