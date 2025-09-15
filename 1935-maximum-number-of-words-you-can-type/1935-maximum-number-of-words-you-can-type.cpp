class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int total = 1;  
        for (char c : text) {
            if (c == ' ') total++;
        }
        istringstream iss(text);
        string word;
        while(iss>> word){
            for(char b: brokenLetters){
                if(word.find(b)!= string::npos){
                    total --;
                    break;
                }
            }
        }
        return total;
    }
};