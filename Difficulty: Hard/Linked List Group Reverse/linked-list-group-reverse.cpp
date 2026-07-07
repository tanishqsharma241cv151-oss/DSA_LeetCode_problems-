/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* reverse(Node* head){
        Node* temp=head;
        Node* prev=nullptr;
        while(temp!=nullptr){
            Node* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;
    }
    Node* getknode(Node*head,int k){
        Node*temp=head;
        while(k>1 && temp->next!=nullptr){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    Node *reverseKGroup(Node *head, int k) {
        if(head==nullptr || head->next==nullptr)return head;
        Node* temp=head;
        Node* prevtail=nullptr;
        while(temp!=nullptr){
            Node*knode=getknode(temp,k);
            Node* nextnode=knode->next;
            knode->next=nullptr;
            reverse(temp);
            if(temp==head){
                head=knode;
            }
            else{
                prevtail->next=knode;
            }
            prevtail=temp;
            temp->next=nextnode;
            temp=temp->next;
        }
       
        return head;
    }
};