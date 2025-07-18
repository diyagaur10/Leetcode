class Solution {
private:
    string getLCS(string text1, string text2) {
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

        // Backtrack to get LCS string
        int i = m, j = n;
        string ans;
        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                ans.push_back(text1[i - 1]);
                i--; j--;
            } else if (t[i - 1][j] > t[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

public:
    string shortestCommonSupersequence(string str1, string str2) {
        string lcs = getLCS(str1, str2);
        string result;
        int i = 0, j = 0;
        for (char c : lcs) {
            while (str1[i] != c) result += str1[i++];
            while (str2[j] != c) result += str2[j++];
            result += c;
            i++; j++;
        }
        result += str1.substr(i);
        result += str2.substr(j);
        return result;
    }
};
