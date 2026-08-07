class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int a=INT_MIN;
        int b=INT_MIN;
        for(int x:nums)
        {
            if(x>a)
            {
                b=a;
                a=x;
            }
            else if(x>b)
            {
                b=x;
            }
        }
        int c = *min_element(nums.begin(),nums.end());
        return a+b-c;

    }
};