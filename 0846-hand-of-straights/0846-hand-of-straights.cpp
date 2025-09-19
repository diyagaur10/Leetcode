class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int, vector<int>, greater<int>>pq;
        map<int,int> mp;
        for(auto v: hand){
            mp[v]++;
            pq.push(v);
        }
         while(!pq.empty()){
            int curr = pq.top();
            pq.pop();
            if (mp[curr] == 0) {
                continue;
            }
            for (int j = 0; j < groupSize; j++) {
                int currCard = curr + j;
                if (mp[currCard] == 0) {
                    return false;
                }
                mp[currCard]--;
            }
        } 
        return true;
        
    }
};