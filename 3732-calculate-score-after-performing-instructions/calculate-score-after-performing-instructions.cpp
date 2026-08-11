class Solution {
public:
    long long calculateScore(vector<string>& i, vector<int>& values) {
        long long score = 0;
        int n = values.size();

        vector<bool> visited(n, false);

        int j = 0;

        while(j >= 0 && j < n)
        {
            if(visited[j])
                return score;

            visited[j] = true;

            if(i[j] == "add")
            {
                score += values[j];
                j++;
            }
            else
            {
                j += values[j];
            }
        }

        return score;
    }
};