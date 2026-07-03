/*
// Representation of a node
class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* arrayToList(vector<int>& arr) {
        int n=arr.size();
        Node* head= new Node(arr[0]);
        Node* temp= head;
        for(int i=1;i<n;i++){
            Node* newnode=new Node(arr[i]);
            temp->next=newnode;
            temp= temp->next;
        }
        return head;
    }
};