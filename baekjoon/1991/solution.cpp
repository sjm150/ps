#include <iostream>
typedef long long lint;
using namespace std;

char l[26], r[26];
void pre(int p) {
    cout << char(p + 'A');
    if (l[p] != '.') pre(l[p] - 'A');
    if (r[p] != '.') pre(r[p] - 'A');
}

void in(int p) {
    if (l[p] != '.') in(l[p] - 'A');
    cout << char(p + 'A');
    if (r[p] != '.') in(r[p] - 'A');
}

void post(int p) {
    if (l[p] != '.') post(l[p] - 'A');
    if (r[p] != '.') post(r[p] - 'A');
    cout << char(p + 'A');
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        char p, c1, c2; cin >> p >> c1 >> c2;
        l[p - 'A'] = c1, r[p - 'A'] = c2;
    }
    pre(0); cout << '\n';
    in(0); cout << '\n';
    post(0); cout << '\n';
}