#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int total = 0;

        
        for (int mask = 0; mask < (1 << n); ++mask) {
            int curr_xor = 0;
            for (int i = 0; i < n; ++i) {
                // If the i-th bit is set, include nums[i]
                if (mask & (1 << i)) {
                    curr_xor ^= nums[i];
                }
            }
            total += curr_xor;
        }

        return total;
    }
};


