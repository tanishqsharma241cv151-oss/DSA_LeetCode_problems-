/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
  public:
    Node* cloneLinkedList(Node* head) {
        if(head==nullptr)return head;
        //step1. create copies and insert them between temp and temp->next.
        Node* temp=head;
        while(temp!=nullptr){
            Node* copy=new Node(temp->data);
            copy->next=temp->next;
            temp->next=copy;
            temp=temp->next->next;  
        }
        //step2. make the copies have the correct random pointers.
        temp=head;
        while(temp!=nullptr){
            if(temp->random==nullptr) temp->next->random=nullptr;
            else temp->next->random=temp->random->next;
            temp=temp->next->next;
        }
        //step3. make the copies have the same next as the original nodes, extract the copies.
        temp=head;
        Node dummy(-1);
        Node* res=&dummy;
        while(temp!=nullptr){
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;
            if(temp==nullptr){
                res->next=nullptr;
                break;
            }   
        }
        return dummy.next;
    }
};