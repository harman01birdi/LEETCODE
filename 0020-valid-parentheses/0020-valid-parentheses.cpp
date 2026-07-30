class Solution {
public:
    bool opening(char ch){
        if(ch == '[' || ch == '{' || ch == '('){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char>st;
        
        for(int i=0; i<s.size(); i++){
            if(opening(s[i])){
                st.push(s[i]);
            }else{
                if(st.size() == 0){
                    return false;
                }
                if(st.top() == '(' && s[i] == ')' ||
                    st.top() == '{' && s[i] == '}' ||
                    st.top() == '[' && s[i] == ']'){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.size() == 0;
    }
};