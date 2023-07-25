#include <iostream>
#include <algorithm>
using namespace std;

int e[200000], o[200000];
int eidx[200000], oidx[200000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int en = 0, on = 0;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            if (a % 2) {
                e[en] = a;
                eidx[en] = i;
                en++;
            } else {
                o[on] = a;
                oidx[on] = i;
                on++;
            }
        }
        sort(e, e + en);
        sort(o, o + on);
        int prev = 0;
        int ei = 0, oi = 0;
        bool ordered = true;
        while (ei < en && oi < on) {
            int curr;
            if (eidx[ei] < oidx[oi]) {
                curr = e[ei];
                ei++;
            } else {
                curr = o[oi];
                oi++;
            }
            if (curr < prev) {
                ordered = false;
                break;
            }
            prev = curr;
        }
        if (ei < en && e[ei] < prev) ordered = false;
        if (oi < on && o[oi] < prev) ordered = false;
        if (ordered) cout << "YES\n";
        else cout << "NO\n";
    }
}