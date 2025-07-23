class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // Helper function to remove target pairs and return points earned
        auto removePair = [](string& s, char first, char second, int score) {
            string temp = "";
            int points = 0;
            for (char c : s) {
                if (!temp.empty() && temp.back() == first && c == second) {
                    temp.pop_back();  // remove first
                    points += score;
                } else {
                    temp.push_back(c);
                }
            }
            s = temp;  // Update the string with the remaining characters
            return points;
        };

        int totalPoints = 0;
        if (x >= y) {
            totalPoints += removePair(s, 'a', 'b', x);
            totalPoints += removePair(s, 'b', 'a', y);
        } else {
            totalPoints += removePair(s, 'b', 'a', y);
            totalPoints += removePair(s, 'a', 'b', x);
        }

        return totalPoints;
    }
};
