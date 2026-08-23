class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int i=1;
        while(st.count(i))
        {
            i++;
        }
        return i;
    }
};