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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //intialize a min heap.
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        //put the heads of all the ll into the pq.
        ListNode* dummy=new ListNode(-1);
        for(int i=0;i<lists.size();i++){
            ListNode* temp=lists[i];
            if(temp!=nullptr){ //guards against lists being an empty vector.
                pq.push({temp->val,temp});
            }
        }
        ListNode* temp=dummy;
        while(!pq.empty()){
            ListNode* change=pq.top().second;
            temp->next=change;
            temp=temp->next;
            change=change->next;
            pq.pop();//removes the smallest val node.
            if(change!=nullptr){
                pq.push({change->val,change});
            }

        }
        return dummy->next;

    }
};