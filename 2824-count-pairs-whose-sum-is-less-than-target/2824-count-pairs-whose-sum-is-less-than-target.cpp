class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;

        int l=0,h=n-1;
        while(l<h) {
            if(nums[l]+nums[h]<target) {
                ans+=h-l;
                l++;
            } else {
                h--;
            }
        }
        return ans;
        
    }
};