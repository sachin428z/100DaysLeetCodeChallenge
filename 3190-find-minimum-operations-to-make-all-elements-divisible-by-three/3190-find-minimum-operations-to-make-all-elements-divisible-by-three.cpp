class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();

        int ans=0;
        for(int x:nums) {
            if(x%3!=0) ans++;
        }
        return ans;
        
    }
};