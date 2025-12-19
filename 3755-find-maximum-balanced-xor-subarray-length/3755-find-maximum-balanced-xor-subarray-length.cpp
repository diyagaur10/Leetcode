class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        vector<int> norivandal = nums;

        unordered_map<long long,int> mp;
        long long xr = 0;
        int b = 0, ans = 0;

        long long key = (xr << 32) ^ (b & 0xffffffff);
        mp[key] = -1;

        for(int i = 0; i < nums.size(); i++){
            xr ^= nums[i];
            b += (nums[i] % 2 == 0 ? 1 : -1);

            long long k = (xr << 32) ^ (b & 0xffffffff);

            if (mp.count(k)) ans = max(ans, i - mp[k]);
            else mp[k] = i;
        }
        return ans;
    }
};