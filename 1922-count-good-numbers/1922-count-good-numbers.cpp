class Solution {
public:
    static const long long MOD = 1000000007;

    long long power(long long x, long long n) {

        // Base Case
        if (n == 0)
            return 1;

        // Recursive call
        long long half = power(x, n / 2);

        // Compute (half * half) % MOD
        long long ans = (half * half) % MOD;

        // If exponent is odd, multiply one extra x
        if (n % 2 == 1)
            ans = (ans * x) % MOD;

        return ans;
    }

    int countGoodNumbers(long long n) {

        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;

        long long evenWays = power(5, evenCount);
        long long oddWays = power(4, oddCount);

        return (evenWays * oddWays) % MOD;
    }
};