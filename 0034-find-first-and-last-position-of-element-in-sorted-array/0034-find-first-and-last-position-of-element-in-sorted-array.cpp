class Solution {
public:
    int firstRange(vector<int>& nums, int target, int low, int high) {
        int index=INT_MAX;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(nums[mid]==target) {
                index=min(index,mid);
                high=mid-1;
            } else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        return (index==INT_MAX)?-1:index;
    }

    int lastRange(vector<int>& nums, int target,int low,int high){
        int index=INT_MIN;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                index=max(index,mid);
                low=mid+1;
            }else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return (index==INT_MIN)?-1:index;
    }
    

    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstRange(nums,target,0,nums.size()-1);
        int last=lastRange(nums,target,0,nums.size()-1);
        return {first,last};
    }
};