class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {

        priority_queue<int> pq;

        long long sum = 0;

        for(int x : nums)
        {
            pq.push(x);
        }

        while(k > 0)
        {
            int t = pq.top();
            pq.pop();

            if(mul > 0)
            {
                sum += 1LL * t * mul;
            }
            else
            {
                sum += t;
            }

            mul--;
            k--;
        }

        return sum;
    }
};