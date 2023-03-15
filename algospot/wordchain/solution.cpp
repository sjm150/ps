#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> words[26];
vector<int> edges[26];
int in_degree[26];
int out_degree[26];

vector<string> rev_order;

void order_dfs(int curr);
void build_order();
bool is_all_edges_used();

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        for (int i = 0; i < 26; i++) {
            words[i].clear();
            edges[i].clear();
            in_degree[i] = out_degree[i] = 0;
        }
        rev_order.clear();

        cin >> n;
        for (int i = 0; i < n; i++) {
            string word;
            cin >> word;
            char from = word.front() - 'a', to = word.back() - 'a';

            words[from].push_back(word);
            edges[from].push_back(to);
            out_degree[from]++;
            in_degree[to]++;
        }

        build_order();
        
        if (is_all_edges_used()) {
            for (auto it = rev_order.rbegin(); it < rev_order.rend(); it++) cout << *it << " ";
            cout << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
}

void order_dfs(int curr) {
    while (!edges[curr].empty()) {
        int next = edges[curr].back();
        string word = words[curr].back();

        edges[curr].pop_back();
        words[curr].pop_back();

        order_dfs(next);

        rev_order.push_back(word);
    }
}

void build_order() {
    for (int curr = 0; curr < 26; curr++) {
        if (in_degree[curr] + 1 == out_degree[curr]) {
            order_dfs(curr);
            break;
        }
    }

    if (rev_order.empty()) {
        for (int curr = 0; curr < 26; curr++) {
            if (out_degree[curr] != 0 && in_degree[curr] == out_degree[curr]) {
                order_dfs(curr);
                break;
            }
        }
    }
}

bool is_all_edges_used() {
    for (int i = 0; i < 26; i++) {
        if (edges[i].size() != 0) return false;
    }

    return true;
}