class Solution {
public:
    int possibleStringCount(string word) {
        vector<pair<char, int>> groups;

        // Step 1: Group consecutive characters
        for (int i = 0; i < word.size(); ) {
            char ch = word[i];
            int count = 0;
            while (i < word.size() && word[i] == ch) {
                count++;
                i++;
            }
            groups.push_back({ch, count});
        }

        // Step 2: For each group with length >= 2, consider reducing it
        // Only one group can be shortened
        int result = 1; // original string without any change

        for (auto &[ch, cnt] : groups) {
            if (cnt >= 2) {
                result += cnt - 1; // we can reduce the group to length 1 to cnt-1
            }
        }

        return result;
    }
};