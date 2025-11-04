class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        pq.push({0,0});

        vector<long long> dist(n, LLONG_MAX);
        
        dist[0]= 0;
        vector<int> ways(n, 0);
        ways[0]= 1;
        const int mod = int(1e9 + 7);
        while(!pq.empty()){
            auto it = pq.top();
            int currDist = it.first;
            int node = it.second;
            pq.pop();
            
            for(auto &[adjNode, time]: adj[node]){
                if(currDist + time < dist[adjNode]){
                    dist[adjNode] = currDist + time;
                    pq.push({dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(currDist + time == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode]  + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};