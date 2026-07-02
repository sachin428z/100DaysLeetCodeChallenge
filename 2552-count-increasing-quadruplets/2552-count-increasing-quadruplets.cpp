class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();

        long long prev_small=0;
        vector<long long> cnt(n,0);
        for(int i=0;i<n;i++) {
            prev_small=0;
            for(int j=0;j<i;j++) {
                if(nums[i]>nums[j]) {
                    prev_small++;
                    ans+=cnt[j];
                } else if(nums[i]<nums[j]) cnt[j]+=prev_small;
            }
        }
        return ans;
    }
};