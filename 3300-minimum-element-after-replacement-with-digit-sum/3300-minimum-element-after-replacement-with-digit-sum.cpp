class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();

        vector<int> ans;
        for(int i=0;i<n;i++) {
            int x=nums[i];
            int ld=0;
            while(x>0) {
              ld+=x%10;
              x=x/10;  
            }
            ans.push_back(ld);
        }
        sort(ans.begin(),ans.end());
        return ans[0];
    }
};