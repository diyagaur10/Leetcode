class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0, r=a.size() - 1;
        while(l<r) {
            if(a[l] + a[r] == target) return {l+1, r+1};
            if(a[l] + a[r] > target) --r;
            else if(a[l] + a[r] < target) ++l;
        }
        return {};
    }
};