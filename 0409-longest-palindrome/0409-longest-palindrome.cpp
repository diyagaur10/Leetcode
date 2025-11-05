class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> hash;
        int oddCnt =0;
        for(int i = 0; i< s.length(); i++){
            hash[s[i]]++;
            if( hash[s[i]] % 2 == 1){
                oddCnt++;
            }
            else oddCnt--;

        }
        if(oddCnt>1){
            return s.length() - oddCnt + 1;
        }
        return s.length();
    }
};