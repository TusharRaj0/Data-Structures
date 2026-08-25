class Solution {
public:
    vector<int> p(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            pse[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
        return pse;
    }

    vector<int> ne(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n, heights.size());
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = (st.empty() ? heights.size() : st.top());
            st.push(i);
        }
        return nse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse = p(heights);
        vector<int> nse = ne(heights);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            ans = max(ans, heights[i] * width);
        }
        return ans;
    }
};
