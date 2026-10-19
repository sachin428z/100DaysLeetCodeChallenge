class Solution {
public:
    vector<int> ans;
    void mergeSort(vector<pair<int,int>>& arr, int left, int right) {
        if(left>=right) return;
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        int j=mid+1;
        for(int i=left;i<=mid;i++) {
            while(j<=right && arr[i].first>arr[j].first) j++;
            ans[arr[i].second]+=j-(mid+1);
        }
        vector<pair<int,int>> merged;
        int first=left, second=mid+1;
        while(first<=mid && second<=right) {
            if(arr[first].first<=arr[second].first) merged.push_back(arr[first++]);
            else merged.push_back(arr[second++]);
        }
        while(first<=mid) merged.push_back(arr[first++]);
        while(second<+right) merged.push_back(arr[second++]);
        for(int i=0;i<merged.size();i++) {
            arr[left+i]=merged[i];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
       int n=nums.size();
       ans.assign(n,0);

       vector<pair<int,int>> arr;
       for(int i=0;i<n;i++) {
        arr.push_back({nums[i],i});

       }
       mergeSort(arr,0,n-1);
       return ans;
    }
};