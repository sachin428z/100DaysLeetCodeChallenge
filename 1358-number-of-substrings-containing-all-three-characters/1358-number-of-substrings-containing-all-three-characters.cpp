class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3,-1);
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++) {
            freq[s[i]-'a']=i;
            cnt=cnt+(1+min(freq[0],min(freq[1],freq[2])));

        }
        return cnt;
    }
};