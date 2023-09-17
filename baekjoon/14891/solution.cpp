#include <bits/stdc++.h>
using namespace std;

const int U = 1, R = 1 << 2, D = 1 << 4, L = 1 << 6;
const int MSK = (1 << 8) - 1;
const int n = 4;

typedef struct Gear {
    int state;

    void init(string& s) {
        state = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            state = state << 1;
            state |= s[i] == '1' ? 1 : 0;
        }
    }

    void rotate_cw() {
        if (state >> 7) state = (state << 1) | 1;
        else state = state << 1;
        state &= MSK;
    }

    void rotate_ccw() {
        if (state & 1) state = (state >> 1) | (1 << 7);
        else state = state >> 1;
    }

    void rotate(bool cw) {
        if (cw) rotate_cw();
        else rotate_ccw();
    }

    bool pulls(Gear& rhs) {
        return ((state & R) == R) ^ ((rhs.state & L) == L);
    }

    int score(int idx) {
        return (state & U) * (1 << idx);
    }
} gear_t;

gear_t gears[n];

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        gears[i].init(s);
    }
    int k; cin >> k;
    vector<int> rotate(n);
    while (k--) {
        fill(rotate.begin(), rotate.end(), 0);
        int i; cin >> i;
        i--;
        cin >> rotate[i];
        for (int l = i - 1; l >= 0; l--) {
            if (gears[l].pulls(gears[l + 1])) rotate[l] = -rotate[l + 1];
            else break;
        }
        for (int r = i; r < n - 1; r++) {
            if (gears[r].pulls(gears[r + 1])) rotate[r + 1] = -rotate[r];
            else break;
        }
        for (int j = 0; j < n; j++) {
            if (rotate[j] == 0) continue;
            gears[j].rotate(rotate[j] == 1);
        }
    }
    int score = 0;
    for (int i = 0; i < n; i++) score += gears[i].score(i);
    cout << score << '\n';
}