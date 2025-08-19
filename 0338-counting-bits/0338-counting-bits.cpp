class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> ans;
        for(int i= 0; i<= n; i++){
            
            ans.push_back(countBitsInNo(i));
        }
        return ans;
    }
    int countBitsInNo(int i){
        int count = 0;
        while(i!=0){
            if(i & 1 == 1) count ++;
            i = i>>1;
        }
        return count;
    }
};