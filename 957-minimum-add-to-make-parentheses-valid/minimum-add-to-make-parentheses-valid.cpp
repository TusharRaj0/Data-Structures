class Solution {
public:
    int minAddToMakeValid(string s) {
        int c=0,a=0;
        int m=s.size();
        for(int i=0;i<m;i++)
        {
            if(s[i]=='(') c++;
            else
            {
                if(c>0) c--;
                else a++;
            }
        }
        return c+a;

    }
};