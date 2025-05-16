class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // efficient, quicksort-based
        return nums;
    }
};
