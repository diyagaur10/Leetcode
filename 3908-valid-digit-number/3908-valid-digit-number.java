class Solution {
    public boolean validDigit(int n, int x) {
        boolean ans = false;
        int ld = n;
        while(n > 0){
            ld = n %10;
            n = n/10;
            if(ld == x){
                ans = true;
            }
        }

        if(ld == x){
            return false;
        }
        else{
            return ans;
        }
    }
}