#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> lines[1000000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        lines[i] = {x, y};
    }
    sort(lines, lines + n);
    pair<int, int> last = lines[0];
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (lines[i].first <= last.second) {
            last.second = max(last.second, lines[i].second);
        } else {
            sum += last.second - last.first;
            last = lines[i];
        }
    }
    sum += last.second - last.first;
    cout << sum << '\n';
}