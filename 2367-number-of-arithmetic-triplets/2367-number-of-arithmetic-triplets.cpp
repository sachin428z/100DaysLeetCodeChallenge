class Solution {
private:
    bool binarySearch(vector<int>&nums, int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return false;
    }

public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n=nums.size();
        int counter = 0;
        for(int i=0;i<n;i++){
          if(binarySearch(nums,nums[i]+diff) && binarySearch(nums,nums[i] + (2*diff))) counter++;
        }

        return counter;
    }
};