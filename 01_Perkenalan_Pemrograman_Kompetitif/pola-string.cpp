#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    int n = s.length();

    int x = -1;
    for (int i = 0; i < 256; i++) {
        if (i * i <= n) {
            x = i;
        } else {
            if (x * x != n) x++;
            break;
        }
    }

    if (x == -1) {
        cout << s << "\n";
        return 0;
    }

    for (int i = 0; i < x; i++) {
        string a(x, '.');
        for (int j = 0; j < x; j++) {
            if ((i * x) + j < n) {
                a[j] = s[(i * x) + j];
            }
        }
        if (i % 2 != 0) {
            reverse(a.begin(), a.end());
        }
        cout << a << "\n";
    }

    return 0;
}
