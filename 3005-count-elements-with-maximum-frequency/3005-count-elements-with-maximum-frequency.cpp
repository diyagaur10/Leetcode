class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int mx =0;
        int cnt =0;
        if(nums.size()== 1)return 1;
        for(int i= 0; i<nums.size(); i++){
            mpp[nums[i]]++;
            mx= max(mx, mpp[nums[i]]);
        }
        for(auto it: mpp){
            if(it.second == mx){
                cnt += mx;
            }
        }
        
        return cnt;
    }
};