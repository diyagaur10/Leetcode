class Solution {
public:
    bool parseBoolExpr(string expression) {
        return evaluate(expression, 0, expression.length() - 1);
    }

private:
    bool evaluate(const string& expr, int start, int end) {
        if (start == end) {
            return expr[start] == 't';
        }

        char op = expr[start];
        vector<bool> results;
        int balance = 0, subStart = start + 2; // skip operator and '('

        for (int i = start + 2; i < end; ++i) {
            if (expr[i] == ',' && balance == 0) {
                results.push_back(evaluate(expr, subStart, i - 1));
                subStart = i + 1;
            } else if (expr[i] == '(') {
                ++balance;
            } else if (expr[i] == ')') {
                --balance;
            }
        }

        // Last subexpression
        results.push_back(evaluate(expr, subStart, end - 1));

        if (op == '!') return !results[0];
        if (op == '&') return all_of(results.begin(), results.end(), [](bool x){ return x; });
        if (op == '|') return any_of(results.begin(), results.end(), [](bool x){ return x; });

        return false; // default
    }
};
