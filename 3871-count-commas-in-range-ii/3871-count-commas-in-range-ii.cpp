class Solution {
public:
    int countCommasPerNumber(long long num) {
        int len = std::to_string(num).length();
        if (len % 3 == 0) {
            return (len / 3) - 1;
        } else {
            return len / 3;
        }
    }

    long long countCommas(long long n) {
        long long total = 0;

        long long start = 1;

        for (int len = 4; len <= 18; len++) {
            long long end = start * 10 - 1;

            if (start > n) break;

            end = min(n, end);

            long long count = end - start + 1;

            int commas = countCommasPerNumber(start);

            total += count * commas;

            start *= 10;
        }

        return total;
    }
};