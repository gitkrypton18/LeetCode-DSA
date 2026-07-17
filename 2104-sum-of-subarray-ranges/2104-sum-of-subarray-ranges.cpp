class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> prevSmall(n), nextSmall(n);
        vector<int> prevGreater(n), nextGreater(n);
        stack<int> st;

        // Previous Smaller
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            prevSmall[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Next Smaller or Equal
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            nextSmall[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        // Previous Greater
        while (!st.empty()) st.pop();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        // Next Greater or Equal
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long minSum = 0, maxSum = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prevSmall[i];
            long long right = nextSmall[i] - i;
            minSum += 1LL * nums[i] * left * right;
        }

        for (int i = 0; i < n; i++) {
            long long left = i - prevGreater[i];
            long long right = nextGreater[i] - i;
            maxSum += 1LL * nums[i] * left * right;
        }

        return maxSum - minSum;
    }
};