#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    while (n) {
        stack<pair<int, int>> s;
        long long int max_area = 0;

        for (int i = 0; i < n; i++) {
            int h;
            cin >> h;

            int idx = i;
            while (!s.empty() && s.top().first >= h) {
                max_area = max(max_area, s.top().first * ((long long int) i - s.top().second));
                idx = s.top().second;
                s.pop();
            }
            s.emplace(h, idx);
        }
        while (!s.empty()) {
            max_area = max(max_area, s.top().first * ((long long int) n - s.top().second));
            s.pop();
        }
        cout << max_area << '\n';

        cin >> n;
    }
}