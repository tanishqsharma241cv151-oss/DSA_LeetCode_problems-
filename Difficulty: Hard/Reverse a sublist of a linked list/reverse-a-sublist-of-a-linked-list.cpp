/* Structure of a Linked List Node
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
    Node* reverseBetween(int a, int b, Node* head) {
        Node dummy(0);
        dummy.next=head;
        Node* curr=head;
        Node* prev=&dummy;
        int count=1;
        while(count<a){
            count++;
            prev=curr;
            curr=curr->next;
        }
        count=0;
        while(count!=b-a){
            count++;
            Node* front=curr->next;
            curr->next=front->next;
            front->next=prev->next;
            prev->next=front;
        }
        return dummy.next;
    }
};