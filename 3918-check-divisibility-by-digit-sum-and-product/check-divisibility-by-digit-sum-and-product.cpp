class Solution {
public:

    int sum = 0;
    int p = 1;

    void d(int n)
    {
        while(n != 0)
        {
            sum += n % 10;
            p *= n % 10;
            n = n / 10;
        }
    }

    bool checkDivisibility(int n) {
        d(n);
        return n % (sum + p) == 0;
    }
};