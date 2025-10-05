class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
         int rows = maze.size();
        int cols = maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; 

        int moves = 0;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!q.empty()) {
            int size = q.size();
            moves++; 
            for(int s = 0; s < size; s++) {
                auto [row, col] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int nr = row + dx[i];
                    int nc = col + dy[i];

                    
                    if(nr < 0 || nc < 0 || nr >= rows || nc >= cols || maze[nr][nc] == '+')
                        continue;

                    
                    if(nr == 0 || nc == 0 || nr == rows - 1 || nc == cols - 1)
                        return moves;

                    maze[nr][nc] = '+'; 
                    q.push({nr, nc});
                }
            }
        }
        return -1;
    }
};