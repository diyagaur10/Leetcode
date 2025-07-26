class Solution {
public:
    int dp[51][51]; // Max n = 50, based on constraints

    int solve(vector<int>& values, int i, int j) {
        if (j - i < 2) return 0; // Less than 3 points can't form a triangle
        if (dp[i][j] != -1) return dp[i][j];

        int minCost = INT_MAX;
        for (int k = i + 1; k < j; ++k) {
            int cost = solve(values, i, k) + solve(values, k, j) + 
                       values[i] * values[k] * values[j];
            minCost = min(minCost, cost);
        }

        return dp[i][j] = minCost;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memset(dp, -1, sizeof(dp));
        return solve(values, 0, n - 1);
    }
};
