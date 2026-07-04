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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* curr=head;
        ListNode* prev=&dummy;
        int count=1;
        while(count<left){
            count++;
            prev=curr;
            curr=curr->next;
        }
        count=0;
        while(count!=right-left){
            count++;
            ListNode* front= curr->next;
            curr->next=front->next;
            front->next=prev->next;
            prev->next=front;    
        }
        return dummy.next;   
    }
};