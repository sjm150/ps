#include <iostream>
using namespace std;
typedef long long ll;

ll Answer;
int n;
string s;
int skip[1000000], seri[1000000];

bool matches(int i, int j) {
    if (s[i] == '(' && s[j] == ')') return true;
    else if (s[i] == '{' && s[j] == '}') return true;
    else return false;
}

int main(int argc, char** argv)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		cin >> n >> s;
        fill(skip, skip + n, -1);
        fill(seri, seri + n, 0);
        for (int i = 0; i < n - 1; i++) {
            int l = i, r = i + 1;
            while (0 <= l && r < n && matches(l, r)) {
                Answer++;
                l--;
                if (0 <= l && skip[l] >= 0) {
                    Answer += seri[l];
                    seri[r] = seri[l] + 1;
                    skip[r] = skip[l];
                    l = skip[l] - 1;
                } else {
                    seri[r] = 1;
                    skip[r] = l + 1;
                }
                r++;
            }
        }
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}