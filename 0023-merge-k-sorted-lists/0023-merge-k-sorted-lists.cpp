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
        priority_queue<int,vector<int>,greater<int>>pq;
        if(lists.size()==0) return NULL;
        for(int i= 0; i<lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp != NULL){
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        ListNode* head= NULL;
        ListNode* tail = NULL;
        while(!pq.empty()){
            int a = pq.top();
            pq.pop();
            ListNode* newNode = new ListNode(a);
            if(head == NULL && tail == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next=newNode;
                tail=newNode;
            }
        }
        return head;
    }
};