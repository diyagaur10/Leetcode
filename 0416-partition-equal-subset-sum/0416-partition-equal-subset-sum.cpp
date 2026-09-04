class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int i =0; i< nums.size(); i++){
            sum+= nums[i];
        }
        if(sum%2 != 0){
            return false;
        }
        
        else{
            return subsetsum(nums, sum/2);
        }
    }


    bool subsetsum(vector<int>& nums, int sum){
        int n= nums.size();
        vector<vector<bool>> t(n +1, vector<bool>(sum + 1 , false));
            for(int i = 0; i<=n; i++){
            t[i][0]= true;
        }
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=sum; j++){
                if(nums[i-1]<=j){
                    t[i][j]= t[i-1][j- nums[i-1]] || t[i-1][j];
                }
                else {
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
};