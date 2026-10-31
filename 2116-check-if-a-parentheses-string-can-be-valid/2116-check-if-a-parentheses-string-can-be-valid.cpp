class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0) {
            return false; // Odd length cannot form valid parentheses
        }

        // Left-to-right pass: Ensure there are enough open brackets
        int openCount = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || locked[i] == '0') {
                openCount++;
            } else { // s[i] == ')' and locked[i] == '1'
                openCount--;
            }
            if (openCount < 0) {
                return false; // Too many ')' encountered
            }
        }

        // Right-to-left pass: Ensure there are enough close brackets
        int closeCount = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')' || locked[i] == '0') {
                closeCount++;
            } else { // s[i] == '(' and locked[i] == '1'
                closeCount--;
            }
            if (closeCount < 0) {
                return false; // Too many '(' encountered
            }
        }

        return true;
    }
};