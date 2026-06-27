class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int> mp;
        int cow=0, bull=0;

        for(int i=0;i<secret.size();i++) mp[secret[i]]++;
        for(int i=0;i<guess.size();i++) {
            if(secret[i]==guess[i]) {
                bull++;
                mp[guess[i]]--;
            }
        }
        for(int i=0;i<guess.size();i++) {
            if(secret[i]!=guess[i] && mp[guess[i]]>0) {
                cow++;
                mp[guess[i]]--;

            }
        }
        string ans=to_string(bull) + "A" +to_string(cow) +"B";
        return ans;
    }
};