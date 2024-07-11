class Solution {
public:
    string reverseParentheses(string s) {
    stack<char> st;
    for (char ch : s) {
        if (ch == ')') {
            // When we find a closing parenthesis, we need to reverse the content inside the most recent pair of parentheses
            string temp;
            while (!st.empty() && st.top() != '(') {
                temp += st.top();
                st.pop();
            }
            // Pop the opening parenthesis
            if (!st.empty() && st.top() == '(') {
                st.pop();
            }
            // Push the reversed content back into the stack
            for (char c : temp) {
                st.push(c);
            }
        } else {
            st.push(ch);
        }
    }

    // The final result will be the concatenation of all characters in the stack
    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    // The stack processes characters in reverse order, so we need to reverse the result string
    reverse(result.begin(), result.end());
    return result;
}
    
};