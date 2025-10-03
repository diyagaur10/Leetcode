class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m = board[0].size();
        vector<vector<int>> viz(n, vector<int>(m, 0));
        queue <pair<int,int>> boundary_o;
        for(int i = 0; i<n; i++){
            for(int j =0; j<m; j++){
                if( i==0 || j==0 || i == n- 1|| j == m-1){
                    if(board[i][j]== 'O'){
                        boundary_o.push({i,j});
                    viz[i][j]= 1;
                    }
                    
                }
            }
        }

        int dx[]= {1,0, -1, 0};
        int dy[]= {0,1,0, -1};
        
        while(!boundary_o.empty()){
            
            int row = boundary_o.front().first;
            int col = boundary_o.front().second;
            boundary_o.pop();
            for(int i =0; i<4; i++){
                int nr= row + dx[i];
                int nc= col + dy[i];
                if(nr>=0 && nr<n && nc>=0 && nc < m && viz[nr][nc] ==0 && board[nr][nc] == 'O'){
                    boundary_o.push({nr,nc});
                    viz[nr][nc]= 1;
                }
            }
        }
        for(int i = 0; i<n; i++){
            for(int j= 0; j<m; j++){
                if(board[i][j]== 'O' && viz[i][j]== 0){
                   board[i][j] =  'X';
                }
            }
        }
        
    }
};