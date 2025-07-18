class Solution {
private:

int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> t(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } else {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        return t[m][n];
    }
public:
    int minDistance(string word1, string word2) {
        
        return word1.size()- longestCommonSubsequence(word1, word2) +word2.size()- longestCommonSubsequence(word1,  word2);
    }
};