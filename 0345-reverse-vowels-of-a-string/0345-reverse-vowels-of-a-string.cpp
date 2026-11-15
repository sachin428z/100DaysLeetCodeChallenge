class Solution {
public:
    bool vowels_check(char ch) {
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        else
            return false;
    }
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length();

        while (i < j) {

            // Left side par vowel find karo
            while (i < j && !vowels_check(s[i]))
                i++;

            // Right side par vowel find karo
            while (i < j && !vowels_check(s[j]))
                j--;

            // Ab dono vowels hi hai
            swap(s[i++], s[j--]);
        }
        return s;
    }
};