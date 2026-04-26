class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> arr;
        vector<int> answer;
        for(int i = 0; i< s.length(); i++){
            if(s[i]== c){
                arr.push_back(i);
            }
        }
        
        for(int i = 0; i< s.length(); i++){
            int minn= INT_MAX;
            for(int j = 0; j< arr.size(); j++){
                minn = min(minn, abs(arr[j]- i));
                
            }
            answer.push_back(minn);
        }
        return answer;
    }
};