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
    Node *insertAtEnd(Node *head, int x) {
        if(head == nullptr) return new Node(x);
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        Node* newnode=new Node(x);
        temp->next=newnode;
        return head;
        
    }
};