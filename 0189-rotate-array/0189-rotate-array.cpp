class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
   
   reverse(nums.begin(),nums.end());
   reverse(nums.begin(),nums.begin()+k);
   reverse(nums.begin()+k,nums.end());


   }
};
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         // If k is greater than or equal to the array size n, rotating k times is equivalent to rotating k % n times.
//         int n=nums.size();
//         k=k%n;
//         while(k>0) {
//             int last=nums[n-1];   // store last one first in var.
//             for(int i=n-1;i>0;i--) {
//                 nums[i]=nums[i-1];  // shift rightside 
//             }
//             nums[0]=last;      // put last at first place
//             k--;            
//         }
//     }
// };