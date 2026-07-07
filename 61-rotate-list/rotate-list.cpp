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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr)return head;
        ListNode* temp=head;
        int len=1;
        while(temp->next!=nullptr){
            len++;
            temp=temp->next;
        }
        temp->next=head;
        k%=len;
        int count=len-k;
        ListNode* newtail=head;
        for(int i=1;i<count;i++){
            newtail=newtail->next;
        }
        head=newtail->next;
        newtail->next=nullptr;
        return head;
    }
    
};