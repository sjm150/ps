#include <iostream>
#include <list>
using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    list<int> l;
    for (int i = 1; i <= n; i++) l.push_back(i);
    cout << "<";
    auto it = l.begin();
    while (l.size() > 1) {
        int mv = (k - 1) % l.size();
        while (mv--) {
            it++;
            if (it == l.end()) it = l.begin();
        }
        cout << *it << ", ";
        it = l.erase(it);
        if (it == l.end()) it = l.begin();
    }
    cout << *it << ">\n";
}