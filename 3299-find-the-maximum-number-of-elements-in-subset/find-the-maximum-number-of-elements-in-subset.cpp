class Solution {
public:
    int maximumLength(vector<int>& nums) {

        typedef long long ll;

        unordered_map<ll,int> mp;

        for(int x : nums)
        {
            mp[x]++;
        }

        int result = 0;

        if(mp[1] % 2)
        {
            result = mp[1];
        }
        else
        {
            result = mp[1] - 1;
        }

        for(auto &[x,freq] : mp)
        {
            if(x == 1) continue;

            int len = 0;
            ll curr = x;

            while(mp.count(curr) && mp[curr] > 1)
            {
                len += 2;
                curr = curr * curr;
            }

            if(mp.count(curr) && mp[curr] == 1)
            {
                len += 1;
            }
            else
            {
                len -= 1;
            }

            result = max(result, len);
        }

        return result;
    }
};