/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp= node;
        node->val= node->next->val;
        node= node->next;

        while(node->next!=NULL && temp->next->next!=NULL ){
            node->val= node->next->val;
        node= node->next;
        temp=temp->next;
        }
        temp->next =NULL;
    }
};