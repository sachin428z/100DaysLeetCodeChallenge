class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;

        sort(nums.begin(),nums.end());
        int l=0, r=n-1;

        while(l<r) {
            int sum=nums[l]+nums[r];
            if(sum==k) {
                cnt++;
                l++;
                r--;
            }
            else if(sum<k) l++;
            else r--;

            
        }
        return cnt;
    }
};