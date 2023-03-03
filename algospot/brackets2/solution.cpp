#include <iostream>
#include <stack>

using namespace std;

bool is_well_formed(string& formula);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        string formula;
        cin >> formula;

        cout << (is_well_formed(formula) ? "YES" : "NO") << endl;
    }
}

bool is_well_formed(string& formula) {
    stack<char> open_brackets;

    for (char c: formula) {
        if (c == '(' || c == '{' || c == '[') {
            open_brackets.push(c);
        } else {
            if (open_brackets.empty()) return false;

            if (c == ')') {
                if (open_brackets.top() != '(') return false;
            } else if (c == '}') {
                if (open_brackets.top() != '{') return false;
            } else if (c == ']') {
                if (open_brackets.top() != '[') return false;
            }

            open_brackets.pop();
        }
    }

    return open_brackets.empty() ? true : false;
}