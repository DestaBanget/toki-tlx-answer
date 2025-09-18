#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (i == 0) {
            vec[0] = a;
        } else {
            vec[i] = vec[i-1] + a;
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int x; cin >> x;
        int ans = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
        cout << ans + 1 << "\n";
    }

    return 0;
}
