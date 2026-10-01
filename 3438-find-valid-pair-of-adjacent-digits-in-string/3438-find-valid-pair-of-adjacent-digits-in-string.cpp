class Solution {
public:
    string findValidPair(string s) {
        int freq[10]={0};

        for(char ch: s) {
            freq[ch-'0']++;
        }
        for(int i=0;i<s.size()-1;i++) {
            int a=s[i]-'0';
            int b=s[i+1]-'0';

            if(a!=b && freq[a]==a && freq[b]==b) return s.substr(i,2);

        }
        return "";

    }
};