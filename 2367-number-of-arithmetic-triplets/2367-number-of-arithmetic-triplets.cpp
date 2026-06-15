class Solution {
    private:
    bool binarySearch(vector<int>&nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high){
            int mid = low + (high - low)/2;
            if (nums[mid] == target){
                return true;
            }
            else if (nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
    }
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int counter = 0;
        for (int i = 0; i < nums.size(); i++){
            if(binarySearch(nums,nums[i] + diff) && binarySearch(nums, nums[i] + (2*diff))){
                counter ++;
            }
        }
        return counter;
    }
};