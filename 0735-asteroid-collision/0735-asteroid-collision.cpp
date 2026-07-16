class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int asteroid : asteroids) {

            while (!st.empty() && st.top() > 0 && asteroid < 0 &&
                   st.top() < abs(asteroid)) {
                st.pop();
            }

            if (!st.empty() && st.top() > 0 && asteroid < 0) {

                if (st.top() == abs(asteroid)) {
                    st.pop();
                }
                // If st.top() > abs(asteroid), current asteroid is destroyed.
            }
            else {
                st.push(asteroid);
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};