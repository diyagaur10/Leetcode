class Solution {
public:
    char findTheDifference(string s, string t) {
        
        int xorr = 0;
        for(char c : s) xorr ^= c;
        for(char c : t) xorr ^= c;
        return xorr;
    }
};