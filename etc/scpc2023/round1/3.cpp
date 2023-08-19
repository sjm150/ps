/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>

using namespace std;

int Answer;
int a[500000];

int main(int argc, char** argv)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        int r = 0;
        int zcnt = 0;
        bool one = false;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] >= 1) {
                r += a[i] - 1;
                a[i] = 1;
                if (r >= i + zcnt) {
                    one = true;
                    break;
                }
            } else {
                if (r > 0) {
                    r--;
                    a[i] = 1;
                } else {
                    zcnt++;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (r == 0 || zcnt == 0) break;
            if (a[i] == 0) {
                a[i] = 1;
                r--;
                zcnt--;
            }
        }
        if (one) {
            Answer = 1;
        } else {
            Answer = n;
            for (int i = 1; i * 2 <= n; i++) {
                if (n % i != 0) continue;
                bool rep = true;
                for (int j = 0; j < i; j++) {
                    for (int k = j + i; k < n; k += i) {
                        if (a[j] != a[k]) {
                            rep = false;
                            break;
                        }
                    }
                    if (!rep) break;
                }
                if (rep) {
                    Answer = i;
                    break;
                }
            }
        }
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << '\n';
        for (int i = 0; i < n; i++) cout << a[i] << ' ';
        cout << '\n';
		cout << Answer << '\n';
	}

	return 0;//Your program should return 0 on normal termination.
}