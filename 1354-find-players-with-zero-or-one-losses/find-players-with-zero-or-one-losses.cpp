class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> win, lose;
        for(auto &m : matches) {
            int w = m[0], l = m[1];
            win[w]++;
            lose[l]++;
        }

        vector<int> zeroLoss, oneLoss;
        unordered_set<int> players;
        for(auto &p : win) players.insert(p.first);
        for(auto &p : lose) players.insert(p.first);

        for(int player : players) {
            if(lose.find(player) == lose.end()) {
                zeroLoss.push_back(player);
            }
            else if(lose[player] == 1) {
                oneLoss.push_back(player);
            }
        }

        sort(zeroLoss.begin(), zeroLoss.end());
        sort(oneLoss.begin(), oneLoss.end());

        return {zeroLoss, oneLoss};
    }
};
