#include <iostream>
#include <map>

using namespace std;

int sum;

int try_insert(map<int, int>& pq_pairs, int p, int q);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        int n;
        map<int, int> pq_pairs;

        cin >> n;
        int p, q;
        cin >> p >> q;
        pq_pairs.emplace(p, q);
        sum = 1;
        for (int i = 1; i < n; i++) {
            cin >> p >> q;
            sum += try_insert(pq_pairs, p, q);
        }

        cout << sum << endl;
    }
}

int try_insert(map<int, int>& pq_pairs, int p, int q) {
    auto it = pq_pairs.lower_bound(p);
    if (q < it->second) return pq_pairs.size();
    if (it == pq_pairs.begin()) {
        pq_pairs.emplace(p, q);
        return pq_pairs.size();
    }

    it--;
    while (it->second < q) {
        if (it == pq_pairs.begin()) {
            pq_pairs.erase(it);
            break;
        } else {
            auto next = it;
            next--;
            pq_pairs.erase(it);
            it = next;
        }
    }

    pq_pairs.emplace(p, q);
    return pq_pairs.size();
}