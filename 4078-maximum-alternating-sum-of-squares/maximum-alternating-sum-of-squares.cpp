class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i++)
        {
            nums[i] = abs(nums[i]);
        }

        sort(nums.begin(), nums.end());

        long long sum = 0;

        int i = 0;
        int j = nums.size() - 1;

        while(i < j)
        {
            sum += 1LL * nums[j] * nums[j];
            sum -= 1LL * nums[i] * nums[i];

            i++;
            j--;
        }

        if(i == j)
        {
            sum += 1LL * nums[i] * nums[i];
        }

        return sum;
    }
};