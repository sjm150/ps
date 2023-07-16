#include <iostream>
#include <algorithm>

using namespace std;

int cards[500000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> cards[i];
    sort(cards, cards + n);
    int m;
    cin >> m;
    while (m--) {
        int num;
        cin >> num;
        cout << upper_bound(cards, cards + n, num) - lower_bound(cards, cards + n, num) << ' ';
    }
    cout << '\n';
}