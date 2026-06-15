class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) 
    {
        vector<int> res(nums.size());
        vector<int> even, odd;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2 == 0) 
                even.push_back(nums[i]);
            else                   
                odd.push_back(nums[i]);
        }

        for(int i = 0; i < nums.size(); i += 2)
        {
            res[i] = even[i / 2];
        }

        for(int i = 1; i < nums.size(); i += 2)
        {
            res[i] = odd[i / 2];
        }

        return res;
    }
};