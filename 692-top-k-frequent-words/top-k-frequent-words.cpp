class Solution {
public:
    struct cmp {
        bool operator()(pair<int,string>& a, pair<int,string>& b) {
            if(a.first == b.first)
                return a.second > b.second;

            return a.first < b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;

        for(int i = 0; i < words.size(); i++)
            mp[words[i]]++;

        priority_queue<pair<int,string>,
                       vector<pair<int,string>>,
                       cmp> pq;

        for(auto it : mp)
            pq.push({it.second, it.first});

        vector<string> ans;

        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};