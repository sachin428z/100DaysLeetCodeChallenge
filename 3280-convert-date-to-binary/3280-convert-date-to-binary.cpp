class Solution {
public:
    string binaryConversion(int n) {
        if (n == 0) return "0";

        string res;

        while (n > 0) {
            if (n % 2 == 1) res += '1';    // odd
            else res += '0';

            n = n / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string convertDateToBinary(string date) {
        string year=binaryConversion(stoi(date.substr(0,4)));
        string month=binaryConversion(stoi(date.substr(5,2)));
        string day=binaryConversion(stoi(date.substr(8,2)));

        return year+"-"+month+"-"+day;
    }
};