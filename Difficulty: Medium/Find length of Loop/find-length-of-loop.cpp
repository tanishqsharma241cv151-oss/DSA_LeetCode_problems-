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
    int lengthOfLoop(Node *head) {
        Node* fast=head;
        Node* slow=head;
        int count=1;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                slow=slow->next;
                while(slow!=fast){
                    count++;
                    slow=slow->next;
                }
                return count;
            }
        }
        return 0;
        
    }
};