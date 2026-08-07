class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {

        priority_queue<int> pq;

        for(int x : nums)
            pq.push(x);

        long long sum = 0;

        while(k-- && !pq.empty())
        {
            int t = pq.top();
            pq.pop();

            sum += 1LL * t * max(1, mul);
            mul--;
        }

        return sum;
    }
};