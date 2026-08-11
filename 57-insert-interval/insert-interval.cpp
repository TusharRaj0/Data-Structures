class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ne) {
        // or push ne vectors in the in vector
        in.push_back(ne);

        // add all vector from in and ne 
        // sort the vector on start if similar then on end bigger one
        sort(in.begin(), in.end());

        // use the merge interval concept like if the end>= start of other merge it
        // create an vector of interval to store these merge one
        vector<vector<int>> ans;

        int s = in[0][0];
        int e = in[0][1];

        for (int i = 1; i < in.size(); i++) {
            if (in[i][0] <= e) {
                e = max(e, in[i][1]);
            } else {
                ans.push_back({s, e});
                s = in[i][0];
                e = in[i][1];
            }
        }

        ans.push_back({s, e});

        return ans;
    }
};