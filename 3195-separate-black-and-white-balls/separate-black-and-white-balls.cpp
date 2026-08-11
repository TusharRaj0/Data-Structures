class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        int j=n-1;
        long long c=0,b=0;
        while(j>=0)
        {
            if(s[j]=='0') b++;
            else c+=b;
            j--;
        }
        return c;
    }
};