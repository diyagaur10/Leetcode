class Solution {
public:
    int getDecimalValue(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;

        // Fix: Traverse the entire list and store values
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int num = 0;
        int power = 0;

        // Fix: Convert binary to decimal from right to left
        for (int i = arr.size() - 1; i >= 0; i--) {
            num += arr[i] * pow(2, power);
            power++;
        }

        return num;
    }
};
