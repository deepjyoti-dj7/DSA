#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c); // Push opening brackets onto stack
        } else {
            if (st.empty()) return false; // No matching opening bracket

            char top = st.top();
            if ((c == ')' && top == '(') || 
                (c == '}' && top == '{') || 
                (c == ']' && top == '[')) {
                st.pop(); // Valid pair, remove from stack
            } else {
                return false; // Mismatched closing bracket
            }
        }
    }

    return st.empty(); // Stack should be empty if all brackets are matched
}

int main() {
    vector<string> testCases = {"()", "()[]{}", "(]", "([)]", "{[]}"};

    for (const string &test : testCases) {
        cout << "String: " << test << " -> " << (isValid(test) ? "Valid" : "Invalid") << endl;
    }

    return 0;
}
