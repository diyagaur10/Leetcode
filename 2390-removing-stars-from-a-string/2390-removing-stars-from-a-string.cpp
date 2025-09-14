class Solution {
public:
    string removeStars(string s) {
        reverse(s.begin(), s.end());
        stack<int> st;
        string ans;
        for(int i =0; i<s.length(); i++){
            st.push(s[i]);
        }
        while(!st.empty()){
            if(st.top() == '*'){
                st.pop();
                ans.pop_back();
            }
            else{
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};