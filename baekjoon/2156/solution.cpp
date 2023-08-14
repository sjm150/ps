#include <iostream>
using namespace std;

int wine[10000];
int excp[10000];
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int n; cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> wine[i];
        sum += wine[i];
    }
    excp[0] = wine[0], excp[1] = wine[1], excp[2] = wine[2];
    for (int i = 3; i < n; i++) {
        excp[i] = wine[i] + min(excp[i - 3], min(excp[i - 2], excp[i - 1]));
    }
    cout << sum - min(excp[n - 3], min(excp[n - 2], excp[n - 1])) << '\n';
}