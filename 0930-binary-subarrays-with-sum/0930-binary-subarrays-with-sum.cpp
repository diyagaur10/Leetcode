class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithAtMostSum(nums, goal) - numSubarraysWithAtMostSum(nums, goal - 1);
    }

private:
    int numSubarraysWithAtMostSum(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int r = 0, l = 0, count = 0, sum = 0;

        while (r < nums.size()) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            count += (r - l + 1);
            r++;
            
        }
        return count;
    }
};