class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char ch : expression) {
            if(ch == ',' ) continue;

            if(ch != ')') {
                st.push(ch);
            } 
            else {
                int t = 0, f = 0;

                while(st.top() != '(') {
                    if(st.top() == 't') t++;
                    else if(st.top() == 'f') f++;
                    st.pop();
                }

                st.pop(); // remove '('

                char op = st.top();
                st.pop();

                if(op == '!') {
                    st.push(f ? 't' : 'f');
                }
                else if(op == '&') {
                    st.push(f ? 'f' : 't');
                }
                else if(op == '|') {
                    st.push(t ? 't' : 'f');
                }
            }
        }

        return st.top() == 't';
    }
};