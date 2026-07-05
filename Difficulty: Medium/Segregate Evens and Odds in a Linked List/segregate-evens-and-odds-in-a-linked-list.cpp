/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/

class Solution {
  public:

    Node *divide(Node *head) {
        if(head==nullptr||head->next==nullptr) return head;
        Node evendummy(0),odddummy(0);
        Node* even=&evendummy;
        Node* odd=&odddummy;
        Node* curr=head;
        while(curr!=nullptr){
            if((curr->data)%2==0){
                even->next=curr;
                even=curr;
            }
            else{
                odd->next=curr;
                odd=curr;
            }
            curr=curr->next;
        }
        odd->next=nullptr;
        even->next=odddummy.next;
        return evendummy.next;
        
    }
};