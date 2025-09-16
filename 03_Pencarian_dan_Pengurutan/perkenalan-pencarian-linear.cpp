#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    int res = INT_MAX, ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (abs(x - a) < res) {
            res = abs(x - a);
            ans = a;
        } else if (abs(x - a) == res) if (ans > a) ans = a;
    }

    cout << ans << "\n";
    return 0;
}
