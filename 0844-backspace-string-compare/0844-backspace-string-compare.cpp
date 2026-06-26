class Solution {
public:
    string build(string& str) {
        stack<char> st;
        for(char ch: str) {
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
        build(s);
        build(t);
        return build(s)==build(t);
    }
};