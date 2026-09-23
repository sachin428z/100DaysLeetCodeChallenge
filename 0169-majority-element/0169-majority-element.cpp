class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int candidate = 0;
        int balance = 0;

        for (int value : nums) {
            if (balance == 0) {
                candidate = value;
            }

            if (value == candidate) {
                balance++;
            } else {
                balance--;
            }
        }

        return candidate;
    }
};