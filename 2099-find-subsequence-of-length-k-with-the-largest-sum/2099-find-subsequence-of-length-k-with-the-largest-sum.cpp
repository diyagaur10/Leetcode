class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // Min-heap to keep track of k largest elements along with their original indices
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minh;
        
        for (int i = 0; i < nums.size(); i++) {
            minh.push({nums[i], i});
            if (minh.size() > k) {
                minh.pop();
            }
        }

        // Extract the k largest elements (they may be out of order)
        vector<pair<int, int>> temp;
        while (!minh.empty()) {
            temp.push_back(minh.top());
            minh.pop();
        }

        // Sort by index to preserve original order
        sort(temp.begin(), temp.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        vector<int> ans;
        for (auto &p : temp) {
            ans.push_back(p.first);
        }

        return ans;
    }
};
