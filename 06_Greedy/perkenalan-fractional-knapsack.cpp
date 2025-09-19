#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;
    cin >> n >> x;

    vector<int> w(n), c(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<pair<double,int>> v;
    for (int i = 0; i < n; i++) {
        double harga = (double)c[i] / w[i];
        v.push_back({harga, w[i]});
    }

    sort(v.begin(), v.end(), [](auto &a, auto &b) {
        return a.first > b.first;
    });

    double ans = 0.0;
    int sisa = x;
    for (int i = 0; i < n && sisa > 0; i++) {
        int ambil = min(sisa, v[i].second);
        ans += ambil * v[i].first;
        sisa -= ambil;
    }

    cout << fixed << setprecision(5) << ans << "\n";
    return 0;
}
