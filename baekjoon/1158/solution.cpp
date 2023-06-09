#include <iostream>
#include <list>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    list<int> l;
    for (int i = 1; i <= n; i++) l.push_back(i);
    int idx = 0;
    auto it = l.begin();

    cout << '<';
    for (int i = 0; i < n - 1; i++) {
        int nidx = (idx + k - 1) % l.size();
        it = next(it, nidx - idx);
        cout << *it << ", ";
        it = l.erase(it);
        idx = nidx;
    }
    cout << *(l.begin()) << ">\n";
}