class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        vector<int> ans;

        int sm = *min_element(nums.begin(), nums.end());
        int mm = *max_element(nums.begin(), nums.end());

        unordered_set<int> st(nums.begin(), nums.end());

        for(int i = sm; i <= mm; i++)
        {
            if(st.find(i) == st.end())
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};