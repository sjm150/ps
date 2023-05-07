#include <string>
#include <vector>
#include <set>

using namespace std;

struct

vector<int> solution(vector<string> operations) {
    multiset<int> tree;
    for (string& op: operations) {
        char c = op[0];
        int num = stoi(op.substr(2, op.size()));
        if (c == 'I') {
            tree.insert(num);
        } else if (!tree.empty()) {
            if (num < 0) tree.erase(tree.begin());
            else tree.erase(--tree.end());
        }
    }
    
    if (tree.empty()) return {0, 0};
    else return {*(--tree.end()), *tree.begin()};
}