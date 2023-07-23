#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<bool> notp(4000001, false);
vector<int> p;
void init(int n) {
    notp[1] = true;
    int i = 2;
    for (; i * i <= n; i++) {
        if (notp[i]) continue;
        p.push_back(i);
        for (int j = i * i; j <= n; j += i) notp[j] = true;
    }
    for (; i <= n; i++) {
        if (!notp[i]) p.push_back(i);
    }
    p.push_back(0);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    init(n);
    int s = 0, e = 0;
    int sum = 0;
    int cnt = 0;
    while (e <= p.size()) {
        if (sum < n) sum += p[e++];
        else sum -= p[s++];
        if (sum == n) cnt++;
    }
    cout << cnt << '\n';
}