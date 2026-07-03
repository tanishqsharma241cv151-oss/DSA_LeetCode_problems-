/*
class Node {
  public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertPos(Node *head, int pos, int val) {
        if(head==nullptr) return new Node(val);
        if(pos==1){
            Node* newhead=new Node(val);
            newhead->next=head;
            return newhead;
        }
        Node* temp=head;
        int count=0;
        while(temp!=nullptr){
            count++;
            if(count==pos-1){
                Node* newnode=new Node(val);
                newnode->next=temp->next;
                temp->next=newnode;
            }
            temp=temp->next;
        }
        return head;
    }
};