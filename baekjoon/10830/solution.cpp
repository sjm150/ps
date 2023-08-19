#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> mat;
const int mod = 1000;

int n;
mat mul(mat& a, mat& b) {
    mat res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return res;
}

mat a;
mat pow(ll e) {
    if (e == 1) return a;
    mat sqr = pow(e / 2);
    mat res = mul(sqr, sqr);
    if (e % 2 == 0) return res;
    else return mul(res, a);
}

int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    ll b; cin >> n >> b;
    a = mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num; cin >> num;
            a[i][j] = num % mod;
        }
    }
    mat res = pow(b);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << res[i][j] << ' ';
        cout << '\n';
    }
}