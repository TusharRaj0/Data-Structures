class Solution {
public:
bool check(int &n,int t)
{
    int a=n;
    int p=1;
    while(a!=0)
    {
        int d = a%10;
        p=p*d;
        a=a/10;

    }
    if(p%t==0) return true;
    return false;
}
    int smallestNumber(int n, int t) {
        while(n<101)
        {
            if(check(n,t)) return n;
            else
            {
                n=n+1;
            }
        }
        return -1;
    }
};