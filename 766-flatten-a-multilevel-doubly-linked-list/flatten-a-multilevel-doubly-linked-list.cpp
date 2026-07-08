/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr=head;
        stack<Node*>st;
        while(curr!=nullptr){ 
            if(curr->child!=nullptr){
                if(curr->next){
                    Node* front=curr->next;
                    front->prev=nullptr;
                    st.push(front);
                }
                Node* down=curr->child;
                curr->next=curr->child;
                down->prev=curr;
                curr->child=nullptr;
            }
            if(curr->next==nullptr && !st.empty()){
                Node* resume=st.top();
                st.pop();
                curr->next=resume;
                resume->prev=curr;
            }  
            curr=curr->next;
             
        }
        return head;
    }
};