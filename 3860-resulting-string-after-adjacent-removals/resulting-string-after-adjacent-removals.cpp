class Solution {
public:
    string resultingString(string s) {
        stack<char> st;

        for (char ch : s) {
            if (!st.empty()) {
                char top = st.top();
                
                if (abs(top - ch) == 1 || abs(top - ch) == 25) {
                    st.pop(); 
                    continue;
                }
            }
            st.push(ch);
        }

       
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
