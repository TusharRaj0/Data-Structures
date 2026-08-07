class Solution {
public:
    long long maxProduct(vector<int>& nums) {

        int max1 = INT_MIN, max2 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;

        int zeroCount = 0;

        for(int x : nums)
        {
            if(x == 0)
                zeroCount++;

            if(x > max1)
            {
                max2 = max1;
                max1 = x;
            }
            else if(x > max2)
            {
                max2 = x;
            }

            if(x < min1)
            {
                min2 = min1;
                min1 = x;
            }
            else if(x < min2)
            {
                min2 = x;
            }
        }

        if(nums.size() == 3 && zeroCount > 1)
            return 0;

        long long p1 = 1LL * max1 * max2 * 100000LL;
        long long p2 = 1LL * min1 * min2 * 100000LL;
        long long p3 = 1LL * min1 * max1 * (-100000LL);

        return max({p1, p2, p3});
    }
};