class Solution {
public:
    void solve(int index,vector<int>& nums,vector<int>& curr,vector<vector<int>>& ans) {
        if(index==nums.size()) {
            ans.push_back(curr);
            return;
        }
        solve(index+1,nums,curr,ans);
        curr.push_back(nums[index]);
        
        solve(index+1,nums,curr,ans);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>curr;
        solve(0,nums,curr,ans);
        
        return ans;
    }
};