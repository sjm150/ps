#include <iostream>
#include <stack>

using namespace std;

int nge[1000000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    stack<pair<int, int>> s;

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        nge[i] = -1;

        while (!s.empty() && s.top().first < h) {
            nge[s.top().second] = h;
            s.pop();
        }
        s.emplace(h, i);
    }

    for (int i = 0; i < n; i++) cout << nge[i] << ' ';
    cout << '\n';
}