class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;

        int len1 = word1.length();
        int len2 = word2.length();
        int i = 0;

        while (i < len1 && i < len2) {
            s += word1[i];
            s += word2[i];
            i++;
        }

        while (i < len1) {
            s += word1[i];
            i++;
        }

        while (i < len2) {
            s += word2[i];
            i++;
        }

        return s;
    }
};