class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isalpha(s[l])) ++l; // Skip non-alpha characters
            while (l < r && !isalpha(s[r])) --r; // Skip non-alpha characters
            swap(s[l++], s[r--]);
        }
        return s;
    }
};