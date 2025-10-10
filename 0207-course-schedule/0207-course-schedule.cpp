class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> indegree(numCourses);
         vector<vector<int>> adj(numCourses);
         for(int i =0; i<n; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
            indegree[v]++;
         }
         queue<int>q;
         for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        int cnt =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
        
        for(int n: adj[node]) {
                indegree[n]--;
                if(indegree[n] == 0)
                    q.push(n);
            }
        }
        return cnt == numCourses;
    }
};