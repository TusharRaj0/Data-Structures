class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<int,int> mp;
        unordered_map<char,int> smp;

        for(int x : ranks)
            mp[x]++;

        for(char x : suits)
            smp[x]++;

        int m = 0;

        for(auto &x : mp)
            m = max(m, x.second);

        if(smp.size() == 1)
            return "Flush";
        else if(m >= 3)
            return "Three of a Kind";
        else if(m >= 2)
            return "Pair";
        else
            return "High Card";
    }
};