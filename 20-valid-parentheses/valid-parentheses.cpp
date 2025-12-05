class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // Push opening brackets
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } 
            else {
                // If stack is empty, no matching opening bracket
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                // Mismatch cases
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // Valid only if no unmatched opening brackets remain
        return st.empty();
    }
};
