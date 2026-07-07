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
        ListNode* curr=head;
        ListNode* back=nullptr;
        while(curr!=nullptr){
            ListNode* front=curr->next;
            curr->next=back;
            back=curr;
            curr=front;
        }
        return back;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* temp=head;
        int count=1;
        ListNode* knode=temp;
        ListNode*prevtail=nullptr;
        while(temp!=nullptr){
            count++;
            knode=knode->next;
            if(knode==nullptr){break;}
            if(count%k==0 && k!=1){
                ListNode* nextnode=knode->next;
                knode->next=nullptr;
                reverse(temp);
                if(temp==head){
                    head=knode;
                }
                else{
                    prevtail->next=knode;
                }
                prevtail=temp;
                temp->next=nextnode;
                temp=temp->next;
                count++;
                knode=temp;   
            }
        }
        return head;

    }
};