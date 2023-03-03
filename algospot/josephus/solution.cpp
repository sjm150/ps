#include <iostream>
#include <list>

using namespace std;

void print_survivors(int n, int k);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        int n, k;
        cin >> n >> k;

        print_survivors(n, k);
    }
}

void print_survivors(int n, int k) {
    list<int> survivors;
    for (int i = 1; i <= n; i++) {
        survivors.push_back(i);
    }

    int size = n;
    auto cursor = survivors.begin();
    while (size > 2) {
        cursor = survivors.erase(cursor);
        if (cursor == survivors.end()) cursor = survivors.begin();
        size--;

        for (int i = 0; i < (k - 1) % size; i++) {
            cursor++;
            if (cursor == survivors.end()) cursor = survivors.begin();
        }
    }

    cout << survivors.front() << " " << survivors.back() << endl;
}