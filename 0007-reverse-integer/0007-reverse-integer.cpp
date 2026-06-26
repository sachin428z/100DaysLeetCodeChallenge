class Solution {
public:
    int reverse(int x) {
        int rev=0;
        int digit;

        while(x!=0) {
            digit=x%10;
             if ((rev > INT_MAX / 10) || (rev < INT_MIN / 10)) return 0; // before multipliying with 10, check it should didn't exceed
            rev=rev*10+digit;
            x=x/10;
        }
        return rev;
    }
};