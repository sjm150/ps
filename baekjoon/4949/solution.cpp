#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    while (true) {
        stack<bool> s;
        string sentence;
        getline(cin, sentence);
        if (sentence == ".") break;

        bool wellformed = true;
        for (char c: sentence) {
            if (c == '[') {
                s.push(true);
            } else if (c == '(') {
                s.push(false);
            } else if (c == ']') {
                if (!s.empty() && (s.top() == true)) {
                    s.pop();
                } else {
                    wellformed = false;
                    break;
                }
            } else if (c == ')') {
                if (!s.empty() && (s.top() == false)) {
                    s.pop();
                } else {
                    wellformed = false;
                    break;
                }
            }
        }

        if (wellformed && s.empty()) cout << "yes\n";
        else cout << "no\n";
    }
}