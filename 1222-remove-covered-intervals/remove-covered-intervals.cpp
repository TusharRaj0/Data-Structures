class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {

        sort(in.begin(), in.end(), [](vector<int> &a, vector<int> &b) {
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        int n = in.size();
        int c = 0;

        int s = in[0][0];
        int e = in[0][1];

        for(int i = 1; i < n; i++)
        {
            int start = in[i][0];
            int end = in[i][1];

            if(s <= start && e >= end)
            {
                c++;
            }
            else
            {
                s = start;
                e = end;
            }
        }

        return n - c;
    }
};