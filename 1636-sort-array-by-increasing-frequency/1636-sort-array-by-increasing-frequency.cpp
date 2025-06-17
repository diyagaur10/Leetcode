class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        // Custom comparator inside lambda
        auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second; // higher value first
            return a.first > b.first; // lower frequency first
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minh(cmp);

        for (auto& it : mp) {
            minh.push({it.second, it.first});
        }

        vector<int> ans;
        while (!minh.empty()) {
            int freq = minh.top().first;
            int val = minh.top().second;
            for (int i = 0; i < freq; i++) {
                ans.push_back(val);
            }
            minh.pop();
        }

        return ans;
    }
};
