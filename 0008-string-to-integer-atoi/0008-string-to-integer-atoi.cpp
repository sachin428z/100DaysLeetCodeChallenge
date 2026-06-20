#include <climits>
class Solution {
public:
    int helper(const string &s, int i, long long num, int sign) {

        if(i >= s.size() || !isdigit(s[i]))
            return (int)(sign * num);

        num = num * 10 + (s[i] - '0');

        if(sign * num <= INT_MIN)
            return INT_MIN;

        if(sign * num >= INT_MAX)
            return INT_MAX;

        return helper(s, i + 1, num, sign);
    }

    int solve(string s, int i = 0) {

        while(i < s.size() && s[i] == ' ')
            i++;

        int sign = 1;

        if(i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        return helper(s, i, 0, sign);
    }

    int myAtoi(string s) {
        return solve(s);
    }
};