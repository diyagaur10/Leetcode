class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        
        vector<int> vis(n, 0);
        queue<int> q;
        vis[0]= 1;
        q.push(0);

        while(!q.empty()){
            int room = q.front();
            q.pop();
            for(int i = 0; i<rooms[room].size(); i++){
                if(vis[rooms[room][i]] !=1){
                    vis[rooms[room][i]] =1;
                    q.push(rooms[room][i]);
                }
                

            }
        }
        for(int v:vis){
            if(v == 0) return false;
        }
        return true;
    }
};