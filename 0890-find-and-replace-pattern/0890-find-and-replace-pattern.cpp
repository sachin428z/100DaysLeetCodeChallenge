class Solution {
public:
    bool check(string a, string b) {
        unordered_map<char,char> mp1;
        unordered_map<char,char>mp2;

        for(int i=0;i<a.size();i++) {
            if(mp1.count(a[i]) && mp1[a[i]]!=b[i]) return false;
            if(mp2.count(b[i]) && mp2[b[i]]!=a[i]) return false;
            mp1[a[i]]=b[i];
            mp2[b[i]]=a[i]; 
        }
        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto s: words) {
            if(check(s,pattern)) ans.push_back(s);
        }
        return ans;
    }
};