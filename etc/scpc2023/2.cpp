#include <iostream>
#include <algorithm>

using namespace std;

int Answer;
int neg[1000000];
int pos[1000000];

int main(int argc, char** argv)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int n, d; cin >> n >> d;
        int nidx = 0, pidx = 0, zcnt = 0;
        while (n--) {
            int coord; cin >> coord;
            if (coord == 0) zcnt++;
            else if (coord < 0) neg[nidx++] = -coord;
            else pos[pidx++] = coord;
        }
        sort(neg, neg + nidx);
        sort(pos, pos + pidx);
        Answer = max(upper_bound(neg, neg + nidx, d) - neg, upper_bound(pos, pos + pidx, d) - pos) + zcnt;
        for (int i = 0; i < nidx; i++) {
            int r = d - 2 * neg[i];
            if (r <= 0) break;
            if (i != nidx - 1 && neg[i] == neg[i + 1]) continue;
            Answer = max(Answer, i + 1 + zcnt + int(upper_bound(pos, pos + pidx, r) - pos));
        }
        for (int i = 0; i < pidx; i++) {
            int r = d - 2 * pos[i];
            if (r <= 0) break;
            if (i != pidx - 1 && pos[i] == pos[i + 1]) continue;
            Answer = max(Answer, i + 1 + zcnt + int(upper_bound(neg, neg + nidx, r) - neg));
        }
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}