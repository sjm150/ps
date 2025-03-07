#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    while (n--) {
        string a; cin >> a;
        bool ok = true;
        stack<char> st;
        st.push(' ');
        for (char c: a)  {
            if (c == '$') {
                st.push(c);
            } else if (c == '|') {
                st.push(c);
            } else if (c == '*') {
                st.push(c);
            } else if (c == 't') {
                if (st.top() != '|') {
                    ok = false;
                    break;
                }
                st.pop();
            } else if (c == 'j') {
                if (st.top() != '*') {
                    ok = false;
                    break;
                }
                st.pop();
            } else if (c == 'b') {
                if (st.top() != '$') {
                    ok = false;
                    break;
                }
                st.pop();
            }
        }
        if (st.size() > 1) ok = false;
        cout << (ok ? "YES\n" : "NO\n");
    }
}