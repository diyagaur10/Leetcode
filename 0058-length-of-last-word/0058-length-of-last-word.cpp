class Solution {
public:
    int lengthOfLastWord(string s) {
        int count =0;
        int i = s.length()-1;
        while( i >=0 && isspace(s[i])){
            i--;
            
        }
        
        while(i >=0 && !isspace(s[i])){
            count ++;
            i--;
        }
        return count;
    }
};