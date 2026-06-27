class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string str="";
        int n=s.size();
        vector<int> ans(n);

        for(int i=0;i<n;i++) {
                ans[indices[i]]=s[i];
        }
        for(auto ch: ans) str+=ch;
        return str;
    }
};