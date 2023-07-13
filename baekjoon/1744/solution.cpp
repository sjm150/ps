#include <iostream>
#include <algorithm>

using namespace std;

int pnum[50], nnum[50];

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int pidx = 0, nidx = 0;
    int sum = 0;
    while (n--) {
        int num;
        cin >> num;
        if (num == 1) sum += 1;
        else if (num > 0) pnum[pidx++] = num;
        else nnum[nidx++] = num;
    }
    sort(pnum, pnum + pidx, greater<int>());
    sort(nnum, nnum + nidx);
    for (int i = 0; i < pidx - 1; i += 2) sum += pnum[i] * pnum[i + 1];
    if (pidx % 2 == 1) sum += pnum[pidx - 1];
    for (int i = 0; i < nidx - 1; i += 2) sum += nnum[i] * nnum[i + 1];
    if (nidx % 2 == 1) sum += nnum[nidx - 1];
    cout << sum << '\n';
}