class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());

        for(int i=0;i<n;i++) {
          if (ans.empty() || intervals[i][0] > ans.back()[1]) {//current interval starts after the last one ends, it means there is no overlap
            ans.push_back(intervals[i]);
          }
          else {//current interval starts before or exactly at the end of the last one, it means there is overlap
            ans.back() [1]=max(ans.back()[1],intervals[i][1]);
          }
        }
        return ans;
    }
};