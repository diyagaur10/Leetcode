class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--; // Adjust to 0-based index
            char ch = 'A' + (columnNumber % 26);
            result = ch + result; // Prepend character
            columnNumber /= 26;
    }
    return result;
    }
};