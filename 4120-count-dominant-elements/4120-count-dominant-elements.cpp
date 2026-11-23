class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = nums.size();
        int dom = 0;

        if (n == 1) return 1;

        for (int i = 0; i < n; i++) {

            if (i == 0) {
                if (nums[i] >= nums[i + 1])
                    dom++;
            }
            else if (i == n - 1) {
                if (nums[i] >= nums[i - 1])
                    dom++;
            }
            else {
                if (2LL * nums[i] >=
                    (long long)nums[i - 1] + nums[i + 1])
                    dom++;
            }
        }

        return dom;
    }
};