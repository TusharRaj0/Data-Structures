class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorall = 0;  // <-- Change 1 to 0
        bool flag = false;
        for(int n : nums) {
            xorall ^= n;
            if(n != 0) flag = true;
        }
        if(!flag) return 0;
        if(xorall != 0) return nums.size();
        return nums.size() - 1;
    }
};