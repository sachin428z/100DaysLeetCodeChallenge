class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            long long product = 1;

            for(int j = i; j < n; j++) {
                product *= nums[j];

                if(product < k)
                    ans++;
                else
                    break;
            }
        }

        return ans;
    }
};