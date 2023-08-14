#include <iostream>
using namespace std;

int a[1000];
int len[1000], pre[1000];
void print(int cur) {
    if (cur == -1) return;
    print(pre[cur]);
    cout << a[cur] << ' ';
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    len[0] = 1, pre[0] = -1;
    for (int i = 1; i < n; i++) {
        len[i] = 1, pre[i] = -1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && len[i] < len[j] + 1) {
                len[i] = len[j] + 1;
                pre[i] = j;
            }
        }
    }
    int maxl = 0, maxi = 0;
    for (int i = 0; i < n; i++) {
        if (len[i] > maxl) {
            maxl = len[i];
            maxi = i;
        }
    }
    cout << maxl << '\n';
    print(maxi);
    cout << '\n';
}