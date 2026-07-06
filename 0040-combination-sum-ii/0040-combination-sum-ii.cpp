class Solution {
public:
    void findComb2(int ind, int target, vector<int>& arr,
                   vector<vector<int>>& ans, vector<int>& ds) {

        // Base Case
        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        for (int i = ind; i < arr.size(); i++) {

            // Skip duplicate elements at the same recursion level
            if (i > ind && arr[i] == arr[i - 1])
                continue;

            // Since array is sorted, no need to check further
            if (arr[i] > target)
                break;

            // Pick current element
            ds.push_back(arr[i]);

            // Move to next index (each element can be used only once)
            findComb2(i + 1, target - arr[i], arr, ans, ds);

            // Backtrack
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        // Required for duplicate removal and early stopping
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;

        findComb2(0, target, candidates, ans, ds);

        return ans;
    }
};