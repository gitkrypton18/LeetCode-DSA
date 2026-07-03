class Solution {
public:
    int solve(string &s, int i, int sign, long long num) {
        // Base case
        if (i >= s.size() || !isdigit(s[i]))
            return sign * num;

        // Update number
        num = num * 10 + (s[i] - '0');

        // Overflow check
        if (sign == 1 && num > INT_MAX)
            return INT_MAX;

        if (sign == -1 && -num < INT_MIN)
            return INT_MIN;

        // Recursive call
        return solve(s, i + 1, sign, num);
    }

    int myAtoi(string s) {
        int i = 0, n = s.size();

        // Skip leading spaces
        while (i < n && s[i] == ' ')
            i++;

        // Handle sign
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        return solve(s, i, sign, 0);
    }
};