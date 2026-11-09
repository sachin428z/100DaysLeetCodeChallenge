class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> temp = nums;

        // Step 1: Sort the array
        sort(temp.begin(), temp.end());

        // Step 2: Remove duplicates
        temp.erase(unique(temp.begin(), temp.end()), temp.end());

        int m = temp.size();

        // Step 3: LCS DP
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(nums[i-1] == temp[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }
};