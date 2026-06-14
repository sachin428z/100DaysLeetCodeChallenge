class Solution {
public:
    bool checkValidString(string s) {
       int minOpen = 0, maxOpen = 0;

        // Traverse each character in the string
        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else {
                // Treat '*' as '(', ')' or ''
                minOpen--;
                maxOpen++;
            }

            // If maxOpen goes negative, too many closing brackets
            if (maxOpen < 0) return false;

            // minOpen can't be negative
            if(minOpen<0) minOpen=0;
        }

        // String is valid if all opens are closed
        return minOpen == 0;
    }
};