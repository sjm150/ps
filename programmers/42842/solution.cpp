#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<pair<int, int>> out, in;
    for (int i = 1; i * i <= yellow; i++) {
        int w = yellow / i;
        if (yellow == w * i) in.emplace_back(w, i);
    }
    int total = brown + yellow;
    for (int i = 1; i * i <= total; i++) {
        int w = total / i;
        if (total == w * i) out.emplace_back(w, i);
    }
    
    for (auto o: out) {
        for (auto i: in) {
            int wdiff = o.first - i.first;
            int hdiff = o.second - i.second;
            if (wdiff % 2 == 0 && wdiff >= 2 && hdiff % 2 == 0 && hdiff >= 2) return {o.first, o.second};
        }
    }
    return {0, 0};
}