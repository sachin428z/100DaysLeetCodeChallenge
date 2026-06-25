class Solution {
public: 
    bool palindromicNumber(string& s) {
        int l=0;
        int r=s.size()-1;
        while(l<=r) {
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return false;
    }

    bool isStrictlyPalindromic(int n) {
        for(int i=2;i<=n-2;i++) {
            string s="";
            int x=n;
            while(x) {
                s+=to_string(x%i);
                x=x/i;
            }
            reverse(s.begin(),s.end());
            if(!palindromicNumber(s)) return false;
        }
        return true;
    }
};


// class Solution {
// public:
//     bool isStrictlyPalindromic(int n) {
//         return false;
//     }
// };