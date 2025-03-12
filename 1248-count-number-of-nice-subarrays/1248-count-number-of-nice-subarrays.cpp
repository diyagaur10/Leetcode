class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    
    int atMostK(vector<int>& nums, int k) {
        int count = 0, l = 0, odd = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 != 0) odd++;  
            
            while (odd > k) {
                if (nums[l] % 2 != 0) odd--;
                l++;
            }
            
            count += (r - l + 1);
        }
        return count;
    }
};
