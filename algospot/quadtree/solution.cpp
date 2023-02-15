#include <iostream>

using namespace std;

string line;

string read_chunk_upsidedown(int from);

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int max_case;
    cin >> max_case;

    for (int c = 0; c < max_case; c++) {
        cin >> line;

        cout << read_chunk_upsidedown(0) << endl;
    }
}

string read_chunk_upsidedown(int from) {
    if (line[from] == 'x') {
        int idx = from + 1;
        string chunks[4];
        for (int i = 0; i < 4; i++) {
            chunks[i] = read_chunk_upsidedown(idx);
            idx += chunks[i].length();
        }
        return string("x") + chunks[2] + chunks[3] + chunks[0] + chunks[1];
    } else {
        return string("") + line[from];
    }
}
