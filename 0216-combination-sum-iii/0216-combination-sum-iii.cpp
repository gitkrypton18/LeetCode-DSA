class Solution {
public:

    void solve(int start,
               int target,
               int k,
               vector<int> &ds,
               vector<vector<int>> &ans)
    {
        // Valid combination found
        if(target == 0 && ds.size() == k)
        {
            ans.push_back(ds);
            return;
        }

        // Invalid path
        if(target < 0 || ds.size() > k)
            return;

        for(int i = start; i <= 9; i++)
        {
            // Pruning
            if(i > target)
                break;

            // Pick
            ds.push_back(i);

            solve(i + 1,
                  target - i,
                  k,
                  ds,
                  ans);

            // Backtrack
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> ds;

        solve(1, n, k, ds, ans);

        return ans;
    }
};