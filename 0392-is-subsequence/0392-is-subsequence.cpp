class Solution {
public:
    bool isSubsequence(string s, string t) {
        int p1=0, p2=0;
        int count = 0;
        while(p1 < s.size() && p2 < t.size()){
            if(s[p1]== t[p2]){
                count++;
                p1++;
                p2++;
            }
            else p2++;
        }
        if(count != s.size()){
            return false;
        }
        return true;
    }
};