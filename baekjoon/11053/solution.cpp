#include <iostream>

using namespace std;

int num[1000], len[1000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    int maxlen = 1;
    for (int i = 0; i < n; i++) {
        len[i] = 1;
        for (int j = 0; j < i; j++) {
            if (num[i] > num[j]) len[i] = max(len[i], len[j] + 1);
        }
        maxlen = max(maxlen, len[i]);
    }
    cout << maxlen << '\n';
}