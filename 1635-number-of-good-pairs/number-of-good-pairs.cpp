class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>maps;
        int c=0;
        for(int num : nums)
        {
            if(maps.find(num)!=maps.end())
            {
                c+=maps[num];
            }
        
            maps[num]++;
        }
        return c;
    
        
    }
};