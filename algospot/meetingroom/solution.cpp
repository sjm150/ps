#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[100], b[100], c[100], d[100];

vector<vector<int>> adj;

vector<int> assign_meetingroom();

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int _c = 0; _c < max_case; _c++) {
        cin >> n;
        for (int i = 0; i < n ; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

        vector<int> assign = assign_meetingroom();
        if (assign.empty()) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << "POSSIBLE" << endl;
            for (int i = 0; i < n; i++) {
                int sel1 = i * 2, sel2 = i * 2 + 1;
                if (assign[sel1]) cout << a[i] << " " << b[i] << endl;
                else if (assign[sel2]) cout << c[i] << " " << d[i] << endl;
            }
        }
    }
}

bool is_overlapped(int start1, int end1, int start2, int end2) {
    return end1 > start2 && end2 > start1;
}

void add_or_edge(int v1, int v2) {
    // if one is not selected, the other must be selected
    adj[v1 + 1].push_back(v2);
    adj[v2 + 1].push_back(v1);
}

void add_nand_edge(int v1, int v2) {
    // if one is selected, the other cannot be selected
    adj[v1].push_back(v2 + 1);
    adj[v2].push_back(v1 + 1);
}

void init_adj() {
    adj = vector<vector<int>>(n * 4, vector<int>());

    for (int i = 0; i < n; i++) {
        int v1 = i * 4, v2 = i * 4 + 2;
        int start1 = a[i], end1 = b[i], start2 = c[i], end2 = d[i];
        add_or_edge(v1, v2);
        if (is_overlapped(start1, end1, start2, end2)) add_nand_edge(v1, v2);

        for (int j = 0; j < i; j++) {
            int jv1 = j * 4, jv2 = j * 4 + 2;
            int js1 = a[j], je1 = b[j], js2 = c[j], je2 = d[j];
            if (is_overlapped(start1, end1, js1, je1)) add_nand_edge(v1, jv1);
            if (is_overlapped(start1, end1, js2, je2)) add_nand_edge(v1, jv2);
            if (is_overlapped(start2, end2, js1, je1)) add_nand_edge(v2, jv1);
            if (is_overlapped(start2, end2, js2, je2)) add_nand_edge(v2, jv2);
        }
    }
}

int discover_counter, scc_counter;

int scc(vector<int>& stack, vector<int>& discover, vector<int>& scc_group, int curr) {
    int reach = discover[curr] = discover_counter++;
    stack.push_back(curr);

    for (int next: adj[curr]) {
        if (discover[next] < 0) {
            reach = min(reach, scc(stack, discover, scc_group, next));
        } else if (scc_group[next] < 0) {
            reach = min(reach, discover[next]);
        }
    }

    if (reach == discover[curr]) {
        while (true) {
            int v = stack.back();
            stack.pop_back();
            scc_group[v] = scc_counter;
            if (v == curr) break;
        }
        scc_counter++;
    }

    return reach;
}

vector<int> tarjan_scc() {
    vector<int> stack, discover, scc_group;
    discover = scc_group = vector<int>(n * 4, -1);
    discover_counter = scc_counter = 0;

    for (int i = 0; i < n * 4; i++) {
        if (discover[i] < 0) scc(stack, discover, scc_group, i);
    }

    return scc_group;
}

vector<int> assign_meetingroom() {
    vector<int> assign;
    init_adj();
    vector<int> scc_group = tarjan_scc();

    for (int i = 0; i < n * 2; i++) {
        int v = i * 2, nv = i * 2 + 1;
        if (scc_group[v] == scc_group[nv]) return assign;
    }

    vector<pair<int, int>> rev_topo_order;
    for (int i = 0; i < n * 4; i++) rev_topo_order.emplace_back(scc_group[i], i);
    sort(rev_topo_order.begin(), rev_topo_order.end());

    assign = vector<int>(n * 2, -1);
    for (auto& p: rev_topo_order) {
        int v = p.second;
        int idx = v / 2;
        bool is_true = v % 2 == 0;

        if (assign[idx] < 0) assign[idx] = is_true;
    }

    return assign;
}