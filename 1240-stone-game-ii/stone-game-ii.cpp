class Solution {
public:
    int solve(int i, int m, vector<int>& piles, vector<vector<int>>& dp) {
        int n = piles.size();

        if(i >= n)
            return 0;

        if(dp[i][m] != -1)
            return dp[i][m];

        int total = 0;
        int ans = 0;

        for(int x = 1; x <= 2 * m && i + x <= n; x++)
        {
            total += piles[i + x - 1];

            int opponent = solve(i + x, max(m, x), piles, dp);

            int remaining = 0;

            for(int k = i + x; k < n; k++)
                remaining += piles[k];

            ans = max(ans, total + remaining - opponent);
        }

        return dp[i][m] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, 1, piles, dp);
    }
};