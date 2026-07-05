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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //optimal approach.
        ListNode* fast=head; // move fast for n places.
        for(int i=0;i<n;i++){
            fast=fast->next;  //fast stops at n places from the 1st node.
        }
        if(fast==nullptr){
            ListNode* x=head;
            head=head->next;
            delete x;
            x=nullptr;
            return head;
        }
        ListNode* slow=head;
        while(fast->next!=nullptr){ //fast will move for l-n places.
            fast=fast->next;        //slow will also move for l-n places.                   
            slow=slow->next;        //slow will have n more places ahead so itll be at the (n+1)th place from the back.
        }
        ListNode* delnode=slow->next;
        slow->next=slow->next->next;
        delete delnode;
        delnode=nullptr;
        return head;
    }
};