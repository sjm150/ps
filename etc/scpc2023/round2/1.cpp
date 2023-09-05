#include <iostream>
#include <tuple>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int abcda = 0, beda = 1, cea = 2;

ll Answer;
int n;
int num[100000];
int cnts[40];
pi inits[40];

int status(int route, int idx) {
    if (route == abcda) return idx;
    else if (route == beda) return idx + 21;
    else if (route == cea) return idx + 21 + 12;
    else return -1;
}

bool isend(int route, int idx) {
    if (route == abcda) return idx > 20;
    else if (route == beda) return idx > 11;
    else if (route == cea) return idx > 6;
    else return false;
}

pi shortcut(int route, int idx) {
    if (route == abcda && idx == 5) return {beda, 0};
    else if (route == abcda && idx == 10) return {cea, 0};
    else if (route == beda && idx == 3) return {cea, 3};
    else return {route, idx};
}

pi run(int route, int idx) {
    int s = status(route, idx);
    if (cnts[s] < 0) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            idx += num[i];
            if (isend(route, idx)) {
                cnt++;
                route = abcda, idx = 0;
            } else {
                tie(route, idx) = shortcut(route, idx);
            }
        }
        cnts[s] = cnt;
        inits[s] = {route, idx};
    }
    Answer += cnts[s];
    return inits[s];
}

int main(int argc, char** argv)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
        fill(cnts, cnts + 40, -1);
		int k; cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> num[i];
        int route = abcda, idx = 0;
        while (k--) tie(route, idx) = run(route, idx);
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}