#include <iostream>

using namespace std;

int arr[100000];
bool exist[2000000];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (x - arr[i] > 0 && exist[x - arr[i]]) count++;
        else exist[arr[i]] = true;
    }

    cout << count << '\n';
}