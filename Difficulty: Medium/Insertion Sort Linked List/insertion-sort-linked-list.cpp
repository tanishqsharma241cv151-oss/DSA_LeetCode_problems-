/* Structure of linked list Node
class Node {
  public:
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = nullptr;
    }
};*/
class Solution {
  public:
    Node* insertionSort(Node* head) {
        if(head==nullptr || head->next==nullptr) return head;
        Node dummy(0);
        Node* curr=head;
        while(curr!=nullptr){
            Node* prev=&dummy;
            Node* front=curr->next;
            while(prev->next!=nullptr && prev->next->val<=curr->val){
                prev=prev->next;
            }
            curr->next=prev->next;
            prev->next=curr;
            curr=front;
            
        }
        return dummy.next;
    }
};