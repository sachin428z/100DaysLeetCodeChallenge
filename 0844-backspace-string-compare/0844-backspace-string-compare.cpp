class Solution {
public:
    string build(string& s) {
        stack<char> st;
        for(char ch: s) {
            if(ch!='#') st.push(ch);
            else {
                if(!st.empty()) st.pop();
            }
        }
        string res="";
        while(!st.empty()) {
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool backspaceCompare(string s, string t) {
        return build(s)==build(t);
    }
};