class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;

        for(int x : nums)
            minHeap.push(x);

        int operations = 0;

        while(minHeap.top() < k) {
            long long first = minHeap.top();
            minHeap.pop();

            long long second = minHeap.top();
            minHeap.pop();

            minHeap.push(2 * min(first, second) + max(first, second));
            operations++;
        }

        return operations;
    }
};