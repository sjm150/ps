#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    stack<pair<int, int>> s;
    long long int sum = 0;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        int dup = 1;
        while (!s.empty() && s.top().first <= h) {
            if (s.top().first == h) dup += s.top().second;
            sum += s.top().second;
            s.pop();
        }
        if (!s.empty()) sum++;
        s.emplace(h, dup);
    }

    cout << sum << '\n';
}