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
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr){
            ListNode* front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next; //slow will stop at mid in case of odd ll and it will stop at m1 in case of even ll.
        }
        ListNode* newhead=reverse(slow->next);
        slow->next=nullptr;
        ListNode* first=head;
        ListNode* second=newhead;
        while(second!=nullptr){
            ListNode* front1=first->next;
            ListNode* front2=second->next;
            first->next=second;
            first=front1;
            second->next=first;
            second=front2;
        }
        if(first) first->next=nullptr;    
    }
};