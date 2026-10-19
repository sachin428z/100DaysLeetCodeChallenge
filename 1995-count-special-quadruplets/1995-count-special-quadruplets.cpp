class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n-3;i++) {
            for(int j=i+1;j<n-2;j++) {
                for(int k=j+1;k<n-1;k++) {
                    for(int l=k+1;l<n;l++) if(nums[i]+nums[j]+nums[k]==nums[l]) 
                    cnt++;
                }
            }
        }
        return cnt;
    }
};