class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBrackets=0;
        int closeBrackets=0;

        for(char ch: s) {
            if(ch=='(') openBrackets++;
            else openBrackets>0 ? openBrackets-- : closeBrackets++;
        }
       // if((openBrackets+closeBrackets)%2!=0) return -1;
        return (openBrackets)+(closeBrackets);
    }
};