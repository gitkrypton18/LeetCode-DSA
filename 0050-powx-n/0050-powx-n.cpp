class Solution {
public:
    double power(double x, long long n) {
        // Base case
        if (n == 0)
            return 1;

        double half = power(x, n / 2);

        // If n is even
        if (n % 2 == 0)
            return half * half;

        // If n is odd
        return x * half * half;
    }

    double myPow(double x, int n) {
        long long N = n;

        // Handle negative powers
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return power(x, N);
    }
};