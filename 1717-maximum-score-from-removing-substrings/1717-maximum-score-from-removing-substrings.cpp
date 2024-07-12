class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totalPoints = 0;

        // Determine the order of removal based on points
        if (x > y) {
            totalPoints += removeAndCount(s, "ab", x);
            totalPoints += removeAndCount(s, "ba", y);
        } else {
            totalPoints += removeAndCount(s, "ba", y);
            totalPoints += removeAndCount(s, "ab", x);
        }

        return totalPoints;
    }

private:
    int removeAndCount(string &s, const string &pattern, int points) {
        int count = 0;
        string result;
        
        for (char c : s) {
            result.push_back(c);
            if (result.size() >= 2 && result[result.size() - 2] == pattern[0] && result.back() == pattern[1]) {
                result.pop_back();
                result.pop_back();
                count += points;
            }
        }

        // Update s with the remaining string after removal
        s = result;
        return count;
    }
};
