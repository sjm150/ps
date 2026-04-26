#include <bits/stdc++.h>
using namespace std;

int n;
string t;
string ans;

int get_ans(int s, int e) {
    if (s >= e) return 0;
    if (t[s] != t[s + 1]) {
        ans.push_back(t[s]);
        return 2 + get_ans(s + 2, e);
    }
    if (t[e - 1] != t[e]) {
        ans.push_back(t[e - 1]);
        ans += "NN";
        return get_ans(s, e - 2);
    }
    if (t[s] != t[e]) {
        ans.push_back(t[s]);
        ans.push_back('N');
        return 1 + get_ans(s + 1, e - 1);
    }
    int m = e;
    int cnt = 0;
    while (s <= m) {
        if (t[m] == 'S') cnt++;
        else cnt--;
        if (cnt == 0) break;
        m--;
    }
    int back = get_ans(m, e);
    while (back--) ans.push_back('N');
    return get_ans(s, m - 1);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> n >> t;
    get_ans(0, n - 1);
    cout << ans.length() << '\n';
    cout << ans << '\n';
}