class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] == freq[b]) return a > b; // decreasing value if freq same
            return freq[a] < freq[b];             // increasing frequency
        });

        return nums;
    }
};
