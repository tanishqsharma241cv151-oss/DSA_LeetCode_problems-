/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* part(ListNode* head,int size,vector<ListNode*>&ans){
        ListNode dummy(0);
        dummy.next=head;
        ListNode* curr=&dummy;
        while(size>0){
            size--;
            curr=curr->next;
        }
        ListNode* newhead=curr->next;
        curr->next=nullptr;
        ans.push_back(head);
        return newhead;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* temp=head;
        int n=0; //length of the ll;
        while(temp!=nullptr){
            n++;
            temp=temp->next;
        }
        vector<ListNode*>ans;
        while(n>=0 && k>0){
            int size=(n+k-1)/k;
            head=part(head,size,ans);
            n-=size;
            k--;
        }
        return ans;
    }
};