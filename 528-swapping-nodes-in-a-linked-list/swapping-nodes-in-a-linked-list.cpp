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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* fast=&dummy;
        ListNode* slow=head;
        for(int i=0;i<k;i++){
            fast=fast->next; //after this loop fast will be at the kth position from the start.
        }
        if(fast==nullptr) return nullptr;
        ListNode* front=fast;
        int x=front->val;
        while(fast->next!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        front->val=slow->val;
        slow->val=x;
        return head;
    }
};