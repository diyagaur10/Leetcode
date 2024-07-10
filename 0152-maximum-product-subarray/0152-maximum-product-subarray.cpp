class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int n = arr.size();
        double pre=1, suf=1;
        double  ans = INT_MIN;

        for (int i = 0; i < n; i++) {
           if(pre==0) pre=1;
            if(suf==0) suf=1;
            pre= pre * arr[i];
            suf= suf * arr[n-i-1];
            ans= max(ans, max(pre,suf) );
            
        }
        return ans;
    }
};
