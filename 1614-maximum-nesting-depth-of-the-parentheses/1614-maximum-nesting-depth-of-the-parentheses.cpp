class Solution {
public:
    int maxDepth(string s) {
        int p=0;
        int ans=0;
        for(char c: s) {
            if(c=='(') p++;
            else if(c==')') p--;
            ans=max(ans,p);
        }
        return ans;
    }
};