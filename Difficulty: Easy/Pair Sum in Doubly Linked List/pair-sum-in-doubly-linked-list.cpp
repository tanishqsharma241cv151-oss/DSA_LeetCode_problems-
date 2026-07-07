/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        if(head==nullptr || head->next==nullptr) return {};
        vector<pair<int,int>>ans;
        Node*right=head;
        while(right->next!=nullptr){
            right=right->next;
        }
        Node* left=head;
        while(left!=right && left->next!=right){
            if(left->data+right->data==target){
                ans.push_back({left->data,right->data});
                left=left->next;
                right=right->prev;
            }
            else if(left->data+right->data<target){
                left=left->next;
            }
            else if(left->data+right->data>target){
                right=right->prev;
            }
        }
        if(left!=right && left->next==right && left->data+right->data==target){
            ans.push_back({left->data,right->data});
        }
        return ans;
        
    }
};