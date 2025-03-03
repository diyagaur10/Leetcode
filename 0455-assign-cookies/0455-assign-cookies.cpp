class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = s.size();
        int n = g.size();
        int l = 0, r=0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        while(l < m && r < n){
            if(s[l]>= g[r]){
                r++;
            }
            l++;
        }
        return r;
    }
};