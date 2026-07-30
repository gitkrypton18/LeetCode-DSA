class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        int nse, pse;
        int el;

        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i < n; i++) {

            while (!st.empty() && heights[st.top()] > heights[i]) {

                el = st.top();
                st.pop();

                nse = i;
                pse = st.empty() ? -1 : st.top();

                maxArea = max(
                    maxArea,
                    heights[el] * (nse - pse - 1)
                );
            }

            st.push(i);
        }

        while (!st.empty()) {

            nse = n;

            el = st.top();
            st.pop();

            // THIS LINE WAS MISSING
            pse = st.empty() ? -1 : st.top();

            maxArea = max(
                maxArea,
                heights[el] * (nse - pse - 1)
            );
        }

        return maxArea;
    }
};