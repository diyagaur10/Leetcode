class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt =0;
        int bottom = n - 1, left = 0, count = 0;
        while(bottom >= 0 && left <m){
            if(grid[bottom][left]< 0){
                cnt += m - left;
                bottom--;
            }
            else{
                left++;
            }
        }
    return cnt;
    }
};