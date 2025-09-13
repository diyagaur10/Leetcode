class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map <char, int> v;
        unordered_map <char, int> c;
        for(int i = 0; i< s.length(); i++){
            if(s[i] == 'a' ||s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u'){
                v[s[i]] ++;
                
            }
            else{ 
                c[s[i]] ++;
            }
        }
            int vmax= 0, cmax =0;
        for(auto& pair :v){
            vmax = max(vmax,pair.second);
        }
        for(auto& pair: c){
            cmax = max(cmax,pair.second);
        }
        
        return cmax + vmax;
    }
};