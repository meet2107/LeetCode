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
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;

        for(int i=0;i<lists.size();i++){
            if(lists[i] != NULL){
                pq.push({lists[i]->val,lists[i]});
            }
        }

        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();

            int val = top.first;
            dummy->next = new ListNode(val);
            dummy = dummy->next;

            ListNode* nxt = top.second->next;
            if(nxt){
                pq.push({nxt->val,nxt});
            }
        }

        return ans->next;
    }
};
