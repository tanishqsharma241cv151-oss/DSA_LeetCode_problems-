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
    ListNode* merge(ListNode* lefthead,ListNode*righthead){
        ListNode dummy(0);
        ListNode* temp=&dummy;
        ListNode* first=lefthead;
        ListNode* second=righthead;
        while(first!=nullptr && second!=nullptr){
            if(first->val<=second->val){
                temp->next=first;
                first=first->next;
            }
            else{
                temp->next=second;
                second=second->next;
            }
            temp=temp->next;
        }
        if(first) temp->next= first;
        if(second) temp->next=second;
        return dummy.next;
    }
    ListNode* findmiddle(ListNode* head){
        //use tortoise hare algorithm.
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next; 
        }
        //slow will end up on the middle element;
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* middle=findmiddle(head); //finds the middle node.
        ListNode* lefthead=head;
        ListNode* righthead=middle->next;
        middle->next=nullptr;
        lefthead=sortList(lefthead);
        righthead=sortList(righthead);
        return merge(lefthead,righthead);   
    }
};