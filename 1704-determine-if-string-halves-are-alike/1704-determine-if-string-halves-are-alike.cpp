class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
    }

    bool halvesAreAlike(string s) {
        int cnt = 0;

        for(int i = 0; i < s.size()/2; i++) {
            if(isVowel(s[i])) cnt++;
            if(isVowel(s[i + s.size()/2])) cnt--;
        }

        return cnt == 0;
    }
};