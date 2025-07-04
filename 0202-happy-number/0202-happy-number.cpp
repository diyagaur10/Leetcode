class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while (n != 1 && !seen.count(n)) { //to avoid the cycle, If we see the same number again: it means we are in a cycle, and we stop.
            seen.insert(n);
            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};
