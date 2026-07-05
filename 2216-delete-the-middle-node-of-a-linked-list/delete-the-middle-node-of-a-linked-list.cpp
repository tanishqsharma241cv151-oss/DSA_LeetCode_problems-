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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return nullptr;
        ListNode dummy(0);
        dummy.next=head;
        ListNode* fast=head;
        ListNode* slow=&dummy;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;      
            slow=slow->next;
        }
       
        //after the loop concludes slow will end up one behind the middle element.
        ListNode* middle=slow->next;
        slow->next=middle->next;
        delete middle;
        middle=nullptr;
        return dummy.next;
    }
};