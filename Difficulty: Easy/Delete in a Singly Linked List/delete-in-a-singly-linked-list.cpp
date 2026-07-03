/*
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        Node* temp=head;
        if(head==nullptr){
            return nullptr;
        }
        if(x==1){
            head=head->next;
            delete temp;
            temp=nullptr;
            return head;
        }
        int count=0;
        Node*prev=nullptr;
        while(temp!=nullptr){
            count++;
            if(count==x){
                prev->next=prev->next->next;
                delete temp;
                temp=nullptr;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};