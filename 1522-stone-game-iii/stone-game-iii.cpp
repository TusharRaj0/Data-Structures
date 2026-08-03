class Solution {
public:
    int solve(int i, vector<int>& stoneValue, vector<int>& dp)
    {
        int n = stoneValue.size();

        if(i >= n)
            return 0;

        if(dp[i] != INT_MIN)
            return dp[i];

        int ans = INT_MIN;
        int sum = 0;

        for(int j = i; j < min(i + 3, n); j++)
        {
            sum += stoneValue[j];
            ans = max(ans, sum - solve(j + 1, stoneValue, dp));
        }

        return dp[i] = ans;
    }

    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> dp(n, INT_MIN);

        int diff = solve(0, stoneValue, dp);

        if(diff > 0)
            return "Alice";
        else if(diff < 0)
            return "Bob";

        return "Tie";
    }
};