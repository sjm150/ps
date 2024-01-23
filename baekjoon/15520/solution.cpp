#include <bits/stdc++.h>
using namespace std;

int sqrt(int x) {
    int l = 1, r = 31625;
    while (l < r) {
        int m = (l + r) / 2;
        if (m * m > x) r = m;
        else l = m + 1;
    }
    return r - 1;
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int l, r; cin >> l >> r;

    int s = sqrt(r);
    vector<bool> isp(s + 1, true);
    isp[0] = isp[1] = false;
    for (int i = 2; i * i <= s; i++) {
        if (!isp[i]) continue;
        for (int j = i * i; j <= s; j += i) isp[j] = false;
    }

    vector<int> prms;
    for (int i = 2; i <= s; i++) {
        if (isp[i]) prms.push_back(i);
    }

    vector<int> pcnt(r - l + 1, 0), rem(r - l + 1);
    iota(rem.begin(), rem.end(), l);
    for (int p: prms) {
        for (int i = (l + p - 1) / p * p; i <= r; i += p) {
            while (rem[i - l] % p == 0) {
                pcnt[i - l]++;
                rem[i - l] /= p;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < pcnt.size(); i++) {
        if (rem[i] > 1) pcnt[i]++;
        if (binary_search(prms.begin(), prms.end(), pcnt[i])) cnt++;
    }
    cout << cnt << '\n';
}