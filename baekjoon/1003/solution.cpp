#include <iostream>
#include <tuple>

using namespace std;

pair<int, int> fib[41];

void init() {
    fib[0] = {1, 0};
    fib[1] = {0, 1};
    for (int i = 2; i <= 40; i++) {
        fib[i] = {fib[i - 1].first + fib[i - 2].first, fib[i - 1].second + fib[i - 2].second};
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    init();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << fib[n].first << ' ' << fib[n].second << '\n';
    }
}