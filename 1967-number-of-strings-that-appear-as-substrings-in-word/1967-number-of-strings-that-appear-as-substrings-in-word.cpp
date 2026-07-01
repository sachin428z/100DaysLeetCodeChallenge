class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        for(string s: patterns)
        {
            if(word.contains(s)) ans++;
        }

        return ans;
    }
};