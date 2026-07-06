/* Node is defined as
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
    Node* segregate(Node* head) {
        if(head==nullptr && head->next==nullptr) return head;
        Node zerohead(-1);
        Node onehead(-1);
        Node twohead(-1);
        Node* zero=&zerohead;
        Node* one=&onehead;
        Node* two=&twohead;
        Node* temp=head;
        while(temp!=nullptr){
            if(temp->data==0){
                zero->next=temp;
                zero=zero->next;
            }
            else if(temp->data==1){
                one->next=temp;
                one=one->next;
            }
            else{
                two->next=temp;
                two=two->next;
            }
            temp=temp->next;
        }
        two->next=nullptr;
        zero->next=(onehead.next)?onehead.next:twohead.next;
        one->next=twohead.next;
        return zerohead.next;

    }
};