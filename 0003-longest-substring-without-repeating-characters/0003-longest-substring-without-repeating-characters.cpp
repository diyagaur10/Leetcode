class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int n = s.size();
        int r = 0, l = 0, maxlen = 0;
        
        while (r < n) {
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }
            maxlen = max(maxlen, r - l + 1);
            hash[s[r]] = r;
            r++;
        }
        
        return maxlen;
    }
};
