#include <iostream>
#include <algorithm>

using namespace std;

struct Result {
    string name;
    int kor;
    int eng;
    int mat;
};
int n;
Result results[100000];

bool cmp(Result& a, Result& b) {
    if (a.kor == b.kor) {
        if (a.eng == b.eng) {
            if (a.mat == b.mat) return a.name < b.name;
            else return a.mat > b.mat;
        }
        return a.eng < b.eng;
    }
    return a.kor > b.kor;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int kor, eng, mat;
        cin >> name >> kor >> eng >> mat;
        results[i] = Result {name, kor, eng, mat};
    }
    sort(results, results + n, cmp);
    for (int i = 0; i < n; i++) cout << results[i].name << '\n';
}