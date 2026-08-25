class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        int curr = k;
        while (s.count(curr)) {
            curr += k;
        }
        return curr;
    }
};