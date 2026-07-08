class Solution {
public:
    int n;
    unordered_set<string> st;
    int dp[301];

    bool solve(int idx, string &s)
    {
        // Base Case
        if(idx == n)
            return true;

        // Memoization
        if(dp[idx] != -1)
            return dp[idx];

        // Try every possible substring starting at idx
        for(int len = 1; idx + len <= n; len++)
        {
            string temp = s.substr(idx, len);

            if(st.find(temp) != st.end())
            {
                if(solve(idx + len, s))
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict)
    {
        n = s.size();

        memset(dp, -1, sizeof(dp));

        for(string &word : wordDict)
            st.insert(word);

        return solve(0, s);
    }
};