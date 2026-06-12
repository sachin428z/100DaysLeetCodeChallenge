class Solution {
public:
    // Function to find maximum sum after partitioning
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = (int)arr.size();

        // DP array to store max sum from index i to end
        vector<int> dp(n + 1, 0); 

        // Iterate from right to left over the array
        for (int i = n - 1; i >= 0; i--) {
            int maxElem = 0;
            int maxSum = 0;

            // Check all partitions of length 1 to k starting at i
            for (int length = 1; length <= k && i + length <= n; length++) {
                // Update maximum element for current partition
                maxElem = max(maxElem, arr[i + length - 1]);

                // Calculate sum if partition ends here
                int currentSum = maxElem * length + dp[i + length];

                // Update maxSum if currentSum is greater
                maxSum = max(maxSum, currentSum);
            }

            // Store maximum sum for subarray starting at i
            dp[i] = maxSum;
        }

        // Return max sum achievable starting at index 0
        return dp[0];
    }
};
