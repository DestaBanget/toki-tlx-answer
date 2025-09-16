#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    string a, b, y;
    cin >> a >> b >> y;

    vector<int> vec(26, -1);
    vector<int> rev(26, -1);

    for (int i = 0; i < n; i++) {
        int from = b[i] - 'A';
        int to = a[i] - 'A';

        if (vec[from] == -1 && rev[to] == -1) {
            vec[from] = to;
            rev[to] = from;
        } else {
            if (vec[from] != to && rev[to] != from) {
                cout << "Pak Dengklek bingung\n";
                return 0;
            }
        }
    }

    for (char c : y) {
        int idx = c - 'A';
        if (vec[idx] != -1) {
            cout << char(vec[idx] + 'A');
        } else {
            cout << "?";
        }
    }

    return 0;
}
