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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* temp=&dummy;
        ListNode* first=list1;
        ListNode* second=list2;
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
        if(first)temp->next=first;
        else if(second)temp->next=second;
        return dummy.next;
    }
};