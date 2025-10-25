class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revAdj(n);
        vector<int> indegree(n, 0);
        
        // Reverse the graph and calculate indegrees
        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                revAdj[neighbor].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        // Terminal nodes have indegree 0 in the reversed graph
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        
        vector<int> safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);
            
            for (int neighbor : revAdj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }
        
        sort(safe.begin(), safe.end());
        return safe;
    }
};