#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.length();
    int m = s2.length();

    if (n - 1 != m) {
        cout << "Wah, tidak bisa :(\n";
        return 0;
    }

    bool pernah = false;
    bool benar = true;

    for (int i = 0, j = 0; i < n and j < n; ) {
        if (s1[i] == s2[j]) {
            ++i; 
            ++j;
        } else {
            if (!pernah) {
                pernah = true;
                ++i;
            } else {
                benar = false;
                break;
            }
        }
    }

    cout << (benar ? "Tentu saja bisa!" : "Wah, tidak bisa :(") << "\n";

    return 0;
}