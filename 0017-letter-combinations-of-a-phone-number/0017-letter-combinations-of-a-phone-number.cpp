class Solution {
public:
    vector<string> mapping = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void solve(int index,
               string &digits,
               string &curr,
               vector<string> &ans)
    {
        // Base Case
        if(index == digits.size())
        {
            ans.push_back(curr);
            return;
        }

        // Get letters corresponding to current digit
        string &letters = mapping[digits[index] - '0'];

        for(char ch : letters)
        {
            // Choose
            curr.push_back(ch);

            // Explore
            solve(index + 1, digits, curr, ans);

            // Backtrack
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;

        if(digits.empty())
            return ans;

        string curr;

        solve(0, digits, curr, ans);

        return ans;
    }
};