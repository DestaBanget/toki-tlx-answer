#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    map<string, string> mp;

    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        mp[a] = b;
    }

    for (int i = 0; i < q; i++) {
        string x;
        cin >> x;
        if (mp.count(x)) cout << mp[x] << "\n";
        else cout << "NIHIL\n";
    }

    return 0;
}