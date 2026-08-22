class Solution {
public:
    int halveArray(vector<int>& nums) {
        double s = 0;
        priority_queue<double> pq;

        for (int a : nums) {
            s += a;
            pq.push((double)a);
        }

        s = s / 2;
        double sum = 0;
        int c = 0;

        while (sum < s) {
            double x = pq.top();
            pq.pop();
            x = x / 2;
            sum += x;
            pq.push(x);
            c++;
        }

        return c;
    }
};
