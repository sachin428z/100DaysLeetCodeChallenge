class Solution {
public:
    int passwordStrength(string password) {
       int cnt=0;
        set<char>st;
        int n=password.size();
        for(int i=0;i<n;i++){
            char ch=password[i];
            if(!st.count(ch)){
                st.insert(ch);
                if(ch >='a'  && ch<='z'){
                    cnt++;
                }
                else if(ch>='A' && ch<='Z'){
                    cnt=cnt+2;
                }
               else if(ch>='0' && ch<='9'){
                    cnt=cnt+3;
                }
                else{
                    cnt=cnt+5;
                }
            }
        }
        return cnt;
    }
};