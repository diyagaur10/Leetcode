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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* temp = head;
        ListNode* fast = head;
        ListNode* slow = head;

        // Find middle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Find node before slow
        while (temp->next != slow) {
            temp = temp->next;
        }
        temp->next = NULL; // split list

        // Reverse from slow
        ListNode* curr = slow;
        ListNode* prev = NULL;
        while (curr != NULL) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        // Merge halves
        ListNode* p1 = head;
        ListNode* p2 = prev;
        while (p1 && p2) {
            ListNode* n1 = p1->next;
            ListNode* n2 = p2->next;
            p1->next = p2;
            if (n1 == NULL) break;
            p2->next = n1;
            p1 = n1;
            p2 = n2;
        }
    }
};
