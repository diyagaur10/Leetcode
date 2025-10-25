class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         int n = prerequisites.size();
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        
        
        for (int i = 0; i < n; i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);
            
            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        
        
        if (order.size() == numCourses)
            return order;
        else
            return {};
    }
};