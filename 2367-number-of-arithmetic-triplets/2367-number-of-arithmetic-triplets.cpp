class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=0;k<n;k++) {
                    if(nums[k]-nums[j]==diff && nums[j]-nums[i]==diff) count++;
                }
            }
        }
        return count;
    }
};