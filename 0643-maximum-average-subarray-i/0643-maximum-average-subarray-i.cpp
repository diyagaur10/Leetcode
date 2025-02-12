class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum =0 , maxavg;
        for(int i =0; i< k; i++){
            sum += nums[i];
        }

        maxavg = sum/k;

        for(int i = k ; i< nums.size(); i++){
            sum += nums[i] - nums[i - k];
            maxavg = max(maxavg, sum / k);
        }
        return maxavg;

    }
};