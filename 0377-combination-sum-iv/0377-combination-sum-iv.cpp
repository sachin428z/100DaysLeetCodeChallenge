class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target + 1, -1);
        return helper(nums, target, memo);
    }

    int helper(vector<int>& nums, int target, vector<int>& memo) {
        if (target == 0) return 1;
        if (target < 0) return 0;
        if (memo[target] != -1) return memo[target];

        int count = 0;
        for (int num : nums) {
            count += helper(nums, target - num, memo);
        }
        return memo[target] = count;
    }
};