#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<long long> pref(n+1, 0);
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        pref[i] = pref[i-1] + a;
    }

    while (k--) {
        long long b; cin >> b;
        int ans = upper_bound(pref.begin()+1, pref.end(), b) - pref.begin() - 1;
        cout << ans << "\n";
    }

    return 0;
}
