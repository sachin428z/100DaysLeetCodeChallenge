class Solution {
public:
    int countAsterisks(string s) {
        bool inside=false;
        int count=0;

        for(char c: s) {
            if(c=='|') inside=!inside;
            else if(c=='*' && !inside) count++;
        }
        return count;
    }
};