class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count=0;

        for(string word: words) {
            bool consistent=true;

            for(char ch: word) {
                if(allowed.find(ch)==string::npos) {  // remember not found == -1
                    consistent=false;
                    break;
                }
            }
            if(consistent) count++;
        }
        return count;
    }
};