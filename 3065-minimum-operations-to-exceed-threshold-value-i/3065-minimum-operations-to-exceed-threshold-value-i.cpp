class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int op=0;
        for(int num:nums) {
            if(num<k) op++;
        }
        return op;
    }
};