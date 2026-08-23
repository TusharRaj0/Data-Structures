class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0;
        int num=-1;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(c==0)
            {
                num=nums[i];
            }
            if(num==nums[i])
            {
                c++;
            }
            else
            {
                c--;
            }
        }
        return num;
    }
};