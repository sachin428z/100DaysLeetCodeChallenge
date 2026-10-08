class Solution {
public:
    string removeOuterParentheses(string s) {
        string result="";
        int level=0;
        for(char ch:s) {
            if(ch=='(') {
                if(level>0) {result+=ch;}// If balance is greater than 0, it means this '(' is not an // outermost parenthesis
                level++;
            }
            else if(ch==')') {
                level--;    // If balance is greater than 0, it means this ')' is not an  // outermost parenthesis
                if(level>0) result+=ch;
            }
        }
        return result;
    }
};