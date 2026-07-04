class Solution {
public:
    void backtrack(string curr, int open, int close, int n, vector<string> &ans) {

        // Base Case
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Add '('
        if (open < n) {
            curr.push_back('(');
            backtrack(curr, open + 1, close, n, ans);
            curr.pop_back();
        }

        // Add ')'
        if (close < open) {
            curr.push_back(')');
            backtrack(curr, open, close + 1, n, ans);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        string curr = "";
        vector<string> ans;

        backtrack(curr, 0, 0, n, ans);

        return ans;
    }
};