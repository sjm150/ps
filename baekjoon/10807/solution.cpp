#include <iostream>

using namespace std;

int arr[100];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, v;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> v;

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == v) count++;
    }

    cout << count << '\n';
}