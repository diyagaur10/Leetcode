class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int sum = nums[i] + nums[j];

                
                int left = j + 1, right = n - 1, k = j;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] < sum) {
                        k = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }

                count += (k - j);
            }
        }
        return count;
        }
    
};