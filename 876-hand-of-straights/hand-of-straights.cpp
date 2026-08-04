class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {

        int n = hand.size();

        if(n % gs != 0)
            return false;

        unordered_map<int,int> mp;

        for(int x : hand)
        {
            mp[x]++;
        }

        sort(hand.begin(), hand.end());

        int groups = 0;

        for(int i = 0; i < n; i++)
        {
            if(mp[hand[i]] == 0)
                continue;

            groups++;

            for(int j = 0; j < gs; j++)
            {
                if(mp[hand[i] + j] == 0)
                    return false;

                mp[hand[i] + j]--;
            }
        }

        return groups == n / gs;
    }
};