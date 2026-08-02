class Solution {
public:
    int check(int i, int j, vector<vector<int>>& dp, vector<int>& piles)
    {
        if(i == j) return piles[i];

        if(dp[i][j] != -1)
            return dp[i][j];

        int l = piles[i] - check(i + 1, j, dp, piles);
        int r = piles[j] - check(i, j - 1, dp, piles);

        return dp[i][j] = max(l, r);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return check(0, n - 1, dp, piles) >= 0;
    }
};