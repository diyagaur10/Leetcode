class Solution {
public:
    string minWindow(string s, string t) {
        int r = 0, l = 0;
        int n = s.size();
        int m = t.size();
        int minlen = INT_MAX;
        int sind = -1, cnt = 0;
        vector<int> hash(256, 0);
        
        for (char c : t) hash[c]++;
        
        while (r < n) {
            if (hash[s[r]] > 0) cnt++;
            hash[s[r]]--;

            while (cnt == m) {  // Corrected comparison
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sind = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) cnt--;  // Corrected cnt condition
                l++;
            }
            r++;
        }
        return sind == -1 ? "" : s.substr(sind, minlen);
    }
};
