/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution {
  public:
    Node* merge(Node* l1,Node* l2){
        Node dummy(-1);
        Node* curr=&dummy;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->data<=l2->data){
                curr->bottom=l1;
                curr=l1;
                l1=l1->bottom;
            }
            else{
                curr->bottom=l2;
                curr=l2;
                l2=l2->bottom;
            }
            curr->next=nullptr;
        }
        if(l1)curr->bottom=l1;
        if(l2)curr->bottom=l2;
        return dummy.bottom;
    }
    Node *flatten(Node *root) {
        //base case
        if(root==nullptr||root->next==nullptr)return root;
        //going deeper
        Node* mergedroot=flatten(root->next);
        //returning mergedhead
        return merge(root,mergedroot);
    }
};