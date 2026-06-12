class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for (auto bill : bills) {
            if (bill == 5) {
                five++;
            }
            else if (bill == 10) {
                if (five > 0) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            }
            else { // bill == 20
                // Prefer giving 10 + 5
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                // Otherwise give 3 fives
                else if (five >= 3) {
                    five -= 3;
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
