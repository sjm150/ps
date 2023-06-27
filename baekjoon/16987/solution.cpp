#include <iostream>

using namespace std;

int n;
int s[8], w[8];
int max_broken;

void update() {
    int broken = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] <= 0) broken++;
    }
    max_broken = max(max_broken, broken);
}

void hit(int curr) {
    if (curr == n) {
        update();
        return;
    }
    if (s[curr] <= 0) {
        hit(curr + 1);
        return;
    }
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (i == curr || s[i] <= 0) continue;
        total++;
        s[curr] -= w[i];
        s[i] -= w[curr];
        hit(curr + 1);
        s[curr] += w[i];
        s[i] += w[curr];
    }
    if (total == 0) {
        update();
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i] >> w[i];
    hit(0);
    cout << max_broken << '\n';
}