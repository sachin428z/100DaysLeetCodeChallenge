class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans=0,sum=0;
        for(auto it: nums) sum+=it, ans=min(ans,sum);

        return 1-ans;
    }
};