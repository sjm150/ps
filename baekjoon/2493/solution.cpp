#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    stack<pair<int, int>> s;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        while (!s.empty() && s.top().first <= h) s.pop();
        if (s.empty()) cout << 0 << ' ';
        else cout << s.top().second << ' ';
        s.emplace(h, i + 1);
    }
    cout << '\n';
}