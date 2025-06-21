class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue <pair<int, pair<int, int>>> maxh;
        for(int i= 0;i<nums1.size(); i++){
            for(int j = 0; j<nums2.size(); j++){
                maxh.push({nums1[i] + nums2[j], {nums1[i] , nums2[j]}});
                if(maxh.size()> k) maxh.pop();

            }
        }
            vector<vector<int>> res;
            while(!maxh.empty()){
                auto point = maxh.top().second;
                res.push_back({point.first, point.second});
                maxh.pop();
            }
            return res;
        }
    
};