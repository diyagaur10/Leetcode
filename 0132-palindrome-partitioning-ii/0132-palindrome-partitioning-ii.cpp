class Solution {
private:
    vector<vector<int>> t;
    vector<vector<bool>> isPalin;

    void precomputePalindrome(string &s) {
        int n = s.size();
        isPalin.resize(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++) {
            isPalin[i][i] = true; // single char
        }
        for(int i = n-1; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                if(s[i] == s[j]) {
                    if(j - i == 1 || isPalin[i+1][j-1])
                        isPalin[i][j] = true;
                }
            }
        }
    }

    int solve(string &s, int i, int j){
        if(i >= j) return 0;
        if(isPalin[i][j]) return 0;
        if(t[i][j] != -1) return t[i][j];

        int mn = INT_MAX;
        for(int k = i; k <= j - 1; k++){
            if(isPalin[i][k]) {  // only partition if left part is a palindrome
                int temp = 1 + solve(s, k + 1, j);
                mn = min(mn, temp);
            }
        }
        return t[i][j] = mn;
    }

public:
    int minCut(string s) {
        int n = s.length();
        t.resize(n, vector<int>(n, -1));
        precomputePalindrome(s);
        return solve(s, 0, n - 1);
    }
};
