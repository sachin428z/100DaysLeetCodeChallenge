class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int n=nums.size();
        
        int peakSum=0, valleySum=0;
        for(int i=1;i<n-1;i++) {
            if(nums[i-1]<nums[i] && nums[i+1]<nums[i]) peakSum+=nums[i];
            if(nums[i-1]>nums[i] && nums[i+1]>nums[i]) valleySum+=nums[i];
        }
        return peakSum-valleySum;
    }
};