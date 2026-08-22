class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;

        long long score = 0;

        for(int x : nums)
            pq.push(x);

        while(k--)
        {
            int x = pq.top();
            pq.pop();

            score += x;

            pq.push(ceil((double)x / 3));
        }

        return score;
    }
};