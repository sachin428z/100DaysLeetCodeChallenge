class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();

        int cnt=0;
        long long res=0;

        for(int i=0;i<n;i++) {
            if(nums[i]>=minK && nums[i]<=maxK) {
            cnt++;
            res+=cnt;
            } else {
            cnt=0;
            }
        }
        return res;
    }
};