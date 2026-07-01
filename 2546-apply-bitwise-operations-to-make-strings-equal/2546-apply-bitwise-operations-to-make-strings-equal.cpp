class Solution {
public:
    bool makeStringsEqual(string s, string target) {
       if(s==target) return true;

       int cnt0=0,cnt1=0,cnt2=0,cnt3=0;

       for(auto& it: s) {
        if(it=='0') cnt0++;
        else cnt1++;
       }

       for(auto& it: target) {
        if(it=='0') cnt2++;
        else cnt3++;
       }

       if((cnt0 && !cnt1) || (cnt2 && !cnt3)) return false;
       return true;
       
    }
};