class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int INF = 1e9;

        vector<int> prev(amount + 1, 0);
        vector<int> cur(amount + 1, 0);

        // Base case (only first coin)
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                prev[i] = i / coins[0];
            else
                prev[i] = INF;
        }

        // DP transition
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= amount; target++) {
                int notTake = prev[target];

                int take = INF;
                if (coins[ind] <= target)
                    take = 1 + cur[target - coins[ind]];

                cur[target] = min(notTake, take);
            }
            prev = cur;
        }

        int ans = prev[amount];
        if (ans >= INF) return -1;

        return  ans;
    }
};
