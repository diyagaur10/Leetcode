class Solution {
    private:
    void dfs(int row, int col,vector<vector<int>>& ans, vector<vector<int>>& image, int color, int ini_color, int dx[], int dy[] ){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i =0; i< 4; i++){
            int nr = row + dx[i];
            int nc = col + dy[i];
            if(nr >=0 && nr<n && nc>= 0 && nc< m && image[nr][nc] == ini_color && ans[nr][nc]!= color){
                dfs(nr,nc,ans,image,color, ini_color, dx, dy);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini_color = image[sr][sc];
        vector<vector<int>> ans = image;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        dfs(sr,sc,ans,image,color,ini_color, dx, dy);
        return ans;
    }
};