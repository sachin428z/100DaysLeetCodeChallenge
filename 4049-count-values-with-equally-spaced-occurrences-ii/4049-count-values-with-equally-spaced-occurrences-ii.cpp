class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();

        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++) mp[nums[i]].push_back(i);

        int ans=0;
        for(auto [key,val]:mp) {
            if(val.size()<3) continue;
            int diff=val[1]-val[0];
            bool valid=true;

            for(int i=2;i<val.size();i++) {
                if(val[i]-val[i-1]!=diff) {
                    valid=false;
                    break;
                }
            }
            if(valid==true) ans++;
        }
        return ans;
    }
};