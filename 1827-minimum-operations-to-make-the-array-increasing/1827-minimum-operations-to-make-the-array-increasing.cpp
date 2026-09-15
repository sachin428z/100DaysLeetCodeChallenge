class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();

        int output=0;
        for(int i=0;i<n-1;i++) {  // n-1 Runtime error
            if(nums[i]<nums[i+1]) continue;
            else {
                output=output+(nums[i]+1-nums[i+1]);
                nums[i+1]=nums[i]+1;
            }
        }
        return output;
    }
};