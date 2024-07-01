#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        
        // Iterate over the numbers from 0 to n
        for (int i = 0; i <= n; ++i) {
            int flag = 0;
            
            // Check if current number i exists in the vector
            for (int j = 0; j < n; ++j) {
                if (nums[j] == i) {
                    flag = 1;
                    break;
                }
            }
            
            // If current number i does not exist in the vector, return it
            if (flag == 0) {
                return i;
            }
        }
        
        // If all numbers from 0 to n exist in the vector, then n+1 is missing
        return n;
    }
};
