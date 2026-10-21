class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        int n=deliciousness.size();
        
        unordered_map<int,int> mpp;
        int ans=0;
        int MOD=1e9+7;

        for(int i=0;i<n;i++) {
            int num=deliciousness[i];
            for(int power=1;power<=(1<<21);power*=2) {
                int complement=power-num;
                if(mpp.find(complement)!=mpp.end()) {
                    ans=(ans+mpp[complement])%MOD;
                }
            }
            mpp[num]++;  // no. of times element occurred
        }
        return ans;
    }
};