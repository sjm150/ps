#include <iostream>

using namespace std;

int cache[1000000];

int dist(int n) {
    if (cache[n] > 0) return cache[n];
    int& ret = cache[n];
    ret = 1000000;
    if (n % 3 == 0) ret = min(ret, dist(n / 3) + 1);
    if (n % 2 == 0) ret = min(ret, dist(n / 2) + 1);
    ret = min(ret, dist(n - 1) + 1);
    return ret;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    cache[1] = 1;
    cout << dist(n) - 1 << '\n';
}