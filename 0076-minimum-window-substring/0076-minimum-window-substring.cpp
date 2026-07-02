class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        
        if(n < m) return "";
        
        vector<int> hash(256, 0);
        
        // Store frequency of characters in t
        for(int i = 0; i < m; i++) {
            hash[t[i]]++;
        }
        
        int l = 0, r = 0;
        int count = 0;
        int minLength = INT_MAX;
        int startIndex = -1;
        
        while(r < n) {
            
            // If character needed
            if(hash[s[r]] > 0) {
                count++;
            }
            
            hash[s[r]]--;
            
            // When all characters matched
            while(count == m) {
                
                if(r - l + 1 < minLength) {
                    minLength = r - l + 1;
                    startIndex = l;
                }
                
                hash[s[l]]++;
                
                if(hash[s[l]] > 0) {
                    count--;
                }
                
                l++;
            }
            
            r++;
        }
        
        return startIndex == -1 ? "" : s.substr(startIndex, minLength);
    }
};
