class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1 = 0, p2 = 0;
        string ans = "";
        while(p1 < word1.size() && p2 < word2.size()){
            ans.push_back(word1[p1]);
            p1++;
            ans.push_back(word2[p2]);
            p2++;
        }
        while (p1 < word1.size()) {
            ans.push_back(word1[p1++]);
        }

        // Agar word2 lamba hai
        while (p2 < word2.size()) {
            ans.push_back(word2[p2++]);
        }
            return ans;
        
    }
};