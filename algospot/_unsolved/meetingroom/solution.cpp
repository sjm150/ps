#include <iostream>
#include <vector>

using namespace std;

int n;
int a[100], b[100], c[100], d[100];

vector<vector<int>> adj[2];
void init_adj();

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int _c = 0; _c < max_case; _c++) {
        cin >> n;
        for (int i = 0; i < n ; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];
        init_adj();


    }
}

bool is_overlapped(int start1, int end1, int start2, int end2) {
    return end1 > start2 || end2 > start1;
}

void add_or_edge(int v1, int v2) {
    // if one is not selected, the other must be selected
    adj[0][v1].push_back(v2);
    adj[0][v2].push_back(v1);
}

void add_nand_edge(int v1, int v2) {
    // if one is selected, the other cannot be selected
    adj[1][v1].push_back(-v2);
    adj[1][v2].push_back(-v1);
}

void init_adj() {
    adj[0] = adj[1] = vector<vector<int>>(n * 2, vector<int>());

    for (int i = 0; i < n; i++) {
        int v1 = i * 2, v2 = i * 2 + 1;
        int start1 = a[i], end1 = b[i], start2 = c[i], end2 = d[i];
        add_or_edge(v1, v2);
        if (is_overlapped(start1, end1, start2, end2)) add_nand_edge(v1, v2);

        for (int j = 0; j < i; j++) {
            int jv1 = j * 2, jv2 = j * 2 + 1;
            int js1 = a[j], je1 = b[j], js2 = c[j], je2 = d[j];
            if (is_overlapped(start1, end1, js1, je1)) add_nand_edge(v1, jv1);
            if (is_overlapped(start1, end1, js2, je2)) add_nand_edge(v1, jv2);
            if (is_overlapped(start2, end2, js1, je1)) add_nand_edge(v2, jv1);
            if (is_overlapped(start2, end2, js2, je2)) add_nand_edge(v2, jv2);
        }
    }
}