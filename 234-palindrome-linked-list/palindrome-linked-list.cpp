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
    ListNode* reverse(ListNode* temp){
        ListNode* last=nullptr;
        while(temp!=nullptr){
            ListNode* front=temp->next;
            temp->next=last;
            last=temp;
            temp=front;
        }
        return last;
    }
    bool isPalindrome(ListNode* head) {
        //find middle element.
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        //reverse the 2nd half.
        ListNode* newhead=reverse(slow->next);
        slow->next=newhead;
        ListNode* first=head;
        ListNode* second=newhead;
        while(second!=nullptr){
            if(first->val==second->val){ //check the values not the pointers.
                first=first->next;
                second=second->next;
            }
            else{
                return false;
            }
        }
        reverse(newhead); //restore the given list to its original form, very very important as we do not want to tamper with the given data in an interview.
        return true;   
    }
};