class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charCount(26, 0);
    for (char c : chars) {
        charCount[c - 'a']++;
    }

    int totalLength = 0;
    for (string& word : words) {
        vector<int> wordCount(26, 0);
        for (char c : word) {
            wordCount[c - 'a']++;
        }

        bool isGood = true;
        for (int i = 0; i < 26; i++) {
            if (wordCount[i] > charCount[i]) {
                isGood = false;
                break;
            }
        }

        if (isGood) {
            totalLength += word.size();
        }
    }

    return totalLength;
    }
};