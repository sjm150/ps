#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        stack<char> s;
        string word;
        cin >> word;

        for (char c: word) {
            if (!s.empty() && c == s.top()) s.pop();
            else s.push(c);
        }

        if (s.empty()) count++;
    }

    cout << count << '\n';
}