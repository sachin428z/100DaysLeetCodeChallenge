class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();

        int result=0;
        for(int i=0;i<32;i++) {
            int sum=0;
            for(int num: nums) {
                if((num>>i)&1) sum++;
            }
        if(sum%3!=0) result=result|(1<<i);
        }
        return result;
    }
};