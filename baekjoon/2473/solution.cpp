#include <iostream>
#include <algorithm>
typedef long long lint;
using namespace std;

int a[5000], b[5000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int ai = 0, bi = 0;
    while (n--) {
        int v;
        cin >> v;
        if (v > 0) a[ai++] = v;
        else b[bi++] = v;
    }

    sort(a, a + ai);
    sort(b, b + bi);
    int m[3] = {0, 0, 0};
    lint minv = INT64_MAX;
    if (ai >= 3) {
        minv = (lint) a[0] + a[1] + a[2];
        m[0] = a[0], m[1] = a[1], m[2] = a[2];
    }
    if (bi >= 3) {
        if (minv > -((lint) b[bi - 3] + b[bi - 2] + b[bi - 1])) {
            minv = -((lint) b[bi - 3] + b[bi - 2] + b[bi - 1]);
            m[0] = b[bi - 3], m[1] = b[bi - 2], m[2] = b[bi - 1];
        }
    }

    for (int i = 0; i < ai; i++) {
        for (int j = i + 1; j < ai; j++) {
            int idx = lower_bound(b, b + bi, -a[i] - a[j]) - b;
            if (idx < bi && minv > abs((lint) a[i] + a[j] + b[idx])) {
                minv = abs((lint) a[i] + a[j] + b[idx]);
                m[0] = a[i], m[1] = a[j], m[2] = b[idx];
            }
            if (idx > 0 && minv > abs((lint) a[i] + a[j] + b[idx - 1])) {
                minv = abs((lint) a[i] + a[j] + b[idx - 1]);
                m[0] = a[i], m[1] = a[j], m[2] = b[idx - 1];
            }
        }
    }
    for (int i = 0; i < bi; i++) {
        for (int j = i + 1; j < bi; j++) {
            int idx = lower_bound(a, a + ai, -b[i] - b[j]) - a;
            if (idx < ai && minv > abs((lint) b[i] + b[j] + a[idx])) {
                minv = abs((lint) b[i] + b[j] + a[idx]);
                m[0] = b[i], m[1] = b[j], m[2] = a[idx];
            }
            if (idx > 0 && minv > abs((lint) b[i] + b[j] + a[idx - 1])) {
                minv = abs((lint) b[i] + b[j] + a[idx - 1]);
                m[0] = b[i], m[1] = b[j], m[2] = a[idx - 1];
            }
        }
    }
    sort(m, m + 3);
    cout << m[0] << ' ' << m[1] << ' ' << m[2] << '\n';
}