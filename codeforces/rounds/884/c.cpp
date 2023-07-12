#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long int osum = 0, esum = 0;
        int negmax = INT32_MIN;
        bool allneg = true;
        bool isodd = true;
        while (n--) {
            int c;
            cin >> c;
            if (c < 0) {
                negmax = max(negmax, c);
            } else {
                if (isodd) osum += c;
                else esum += c;
                allneg = false;
            }
            isodd = !isodd;
        }
        if (allneg) cout << negmax << '\n';
        else cout << max(osum, esum) << '\n';
    }
}