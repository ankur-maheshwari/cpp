class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        int n = s.length();
        for(int i=0; i<n; i++)
        {
            if(!st.empty() && st.top() == s[i])
            {
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        
        s = "";
        while(!st.empty())
        {
            char x = st.top();
            s += x;
            st.pop();
        }
        
        reverse(s.begin(), s.end());
        return s;
    }
};
