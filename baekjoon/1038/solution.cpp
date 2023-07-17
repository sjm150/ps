#include <iostream>

using namespace std;

int idx = 0;
long long int num[1023];
void sel(long long int curr, int l) {
    if (l == 0) {
        num[idx++] = curr;
        return;
    }
    for (int i = 0; i < curr % 10; i++) sel(curr * 10 + i, l - 1);
}

void init() {
    num[idx++] = 0;
    for (int l = 1; l <= 10; l++) {
        for (int i = 1; i < 10; i++) sel(i, l - 1);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    init();
    if (n >= idx) cout << -1 << '\n';
    else cout << num[n] << '\n';
}