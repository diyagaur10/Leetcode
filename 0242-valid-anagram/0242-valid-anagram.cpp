class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if (s.length() != t.length()) {
            return false;
        }

        map<char, int> mpp;

        
        for (char c : s) {
            mpp[c]++;
        }

        for (char c : t) {
            mpp[c]--;
            // If any character count goes below zero, they are not anagram
            if (mpp[c] < 0) {
                return false;
            }
        }

        // If the map is balanced, strings are anagrams
        return true;
    }
};