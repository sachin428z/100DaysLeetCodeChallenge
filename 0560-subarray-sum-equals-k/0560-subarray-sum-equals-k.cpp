class Solution {
public:
   int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    count[0] = 1;   // empty prefix
    int sum = 0, ans = 0;
    for (int n : nums) {
        sum += n;
        ans += count[sum - k];   // how many prefixes make this sum - k
        count[sum]++;
    }
    return ans;
}
};