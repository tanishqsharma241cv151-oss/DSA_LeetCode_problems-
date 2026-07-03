/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        Node* temp = head;
        int count = 0;
        while(count < p) {
            temp = temp->next;
            count++;
        }

        Node* newnode = new Node(x);
        Node* front = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = front;
        if(front != nullptr) front->prev = newnode;

        return head;
        
    }
};