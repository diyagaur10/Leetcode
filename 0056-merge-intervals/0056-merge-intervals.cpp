class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervels) {
        int n=intervels.size();
        sort(intervels.begin(), intervels.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(ans.empty() || intervels[i][0] > ans.back()[1]){
                ans.push_back(intervels[i]);
            }
            else{
                ans.back()[1]= max(ans.back()[1], intervels[i][1]);
            }
        }
            
        return ans;
    }
};