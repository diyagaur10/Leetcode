class Solution {
public:
    int numberOfSubstrings(string s) {
        vector <int> list(3,-1); //list of last seen ch in string
        int count =0;
        for(int i =0 ; i < s.size(); i++){
            list[s[i] - 'a'] = i; //storing the value of index in the hash arr
            if(list[0] != -1 && list[1] != -1 && list[2] != -1 ){
                count = count + 1 + min({list[0], list[1],list[2]});
            }
        }
        return count;
    }
};