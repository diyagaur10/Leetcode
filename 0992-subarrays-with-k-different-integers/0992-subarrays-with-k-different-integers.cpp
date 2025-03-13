#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }

private:
    int atMostK(vector<int>& nums, int k) {
        if (k == 0) return 0; // Edge case
        
        unordered_map<int, int> freq;
        int l = 0, r = 0, count = 0;

        while (r < nums.size()) {
            freq[nums[r]]++;

            while (freq.size() > k) { // Shrink window if distinct count > k
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }
                l++;
            }

            count += (r - l + 1); // Count valid subarrays
            r++;
        }

        return count;
    }
};
