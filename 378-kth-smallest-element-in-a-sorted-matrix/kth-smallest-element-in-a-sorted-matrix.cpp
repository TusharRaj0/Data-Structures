class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        for(int i = 0; i < mat.size(); i++)
        {
            pq.push({mat[i][0], i, 0});
        }

        int ans = 0;

        while(k--)
        {
            auto [val, row, col] = pq.top();
            pq.pop();

            ans = val;

            if(col + 1 < n)
            {
                pq.push({mat[row][col + 1], row, col + 1});
            }
        }

        return ans;
    }
};