#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
    cin.tie(0); ios_base::sync_with_stdio(0);
	int T, test_case;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		int n, a, b; cin >> n >> a >> b;
        if (a < b) {
            int temp = a;
            a = b;
            b = temp;
        }
        for (int i = 0; i * a <= n; i++) {
            int x = n - i * a;
            if (x % b == 0) {
                Answer = i + x / b;
                break;
            }
        }
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}