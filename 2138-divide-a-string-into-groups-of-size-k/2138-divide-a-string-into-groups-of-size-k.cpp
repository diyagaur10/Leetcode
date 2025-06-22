class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        for(int i= 0; i<s.size(); i+=k){
            string substr= s.substr(i, k);
            
            if(k>substr.size()){
               
                    substr.append(k- substr.size(), fill);
            }
                ans.push_back(substr);
            
          
        }
        return ans; 
    }
};