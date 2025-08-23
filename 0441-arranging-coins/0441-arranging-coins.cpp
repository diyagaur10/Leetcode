class Solution {
public:
    int arrangeCoins(int n) {
        int low =1;
        int high = n;
        
        while(low<=high){
            int mid= low + (high -low)/2;
            long long  count = (long long)mid*(mid+1)/2;
            if(count == n){
                return mid;
            }
            else if(count> n){
                high = mid - 1;
            }
            else low= mid+1;
        }
        return high;
    }
};