#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    long long d;
    cin >> n >> d;

    vector<pair<long long, long long>> v(n); 
    // {harga, bebek}
    for (int i = 0; i < n; i++) {
        long long h, b;
        cin >> h >> b;
        v[i] = {h, b};
    }

    sort(v.begin(), v.end());

    long long jawab = 0;
    for (int i = 0; i < n; i++) {
        long long h = v[i].first;
        long long b = v[i].second;

        if (d < h) break;

        long long bisa = min(b, d / h);
        jawab += bisa;
        d -= bisa * h;
    }

    cout << jawab << "\n";
    return 0;
}