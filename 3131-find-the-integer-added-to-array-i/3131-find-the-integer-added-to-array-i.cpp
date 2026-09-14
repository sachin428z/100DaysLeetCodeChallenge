class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        int n=nums1.size();
        return nums2[n-1]-nums1[n-1]; // diff or 1st index 
    }
};