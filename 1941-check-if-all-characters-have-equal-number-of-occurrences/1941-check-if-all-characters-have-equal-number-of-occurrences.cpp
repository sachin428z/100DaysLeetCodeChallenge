class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int n=s.size();
        unordered_map<char,int> mp;

        for(auto it: s) {
            mp[it]++;
        }

        int first=mp[s[0]];

        for(auto it: mp) {
            if(it.second!=first) return false;
        }
        return true;
    }
};

// //
//         for (int i = 0; i < n; i++) {
//             mp[s[i]]++;          // Count frequency of each character
//         }

// also works
