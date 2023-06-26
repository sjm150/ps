#include <iostream>

using namespace std;

int k;
int s[12];
bool sel[12];

void print() {
    for (int i = 0; i < k; i++) {
        if (sel[i]) cout << s[i] << ' ';
    }
    cout << '\n';
}

void select(int i, int selected) {
    if (selected == 6) {
        print();
        return;
    }
    if (i == k) return;
    sel[i] = true;
    select(i + 1, selected + 1);
    sel[i] = false;
    select(i + 1, selected);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while (true) {
        cin >> k;
        if (k == 0) break;
        for (int i = 0; i < k; i++) cin >> s[i];
        select(0, 0);
        cout << '\n';
    }
}