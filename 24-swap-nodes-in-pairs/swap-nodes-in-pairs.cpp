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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* prev=&dummy;
        ListNode* curr=head;
        while(curr!=nullptr && curr->next!=nullptr){
            ListNode* front=curr->next;
            curr->next=front->next;
            front->next=curr;
            prev->next=front;
            prev=curr;
            curr=curr->next;
        }
        return dummy.next;
    }
};