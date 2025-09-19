#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<long long,long long>> v; 
    for (int i = 0; i < n; i++) {
        long long s, d;
        cin >> s >> d;
        v.push_back({s + d, s});
    }

    sort(v.begin(), v.end());

    long long now = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        long long selesai = v[i].first;
        long long mulai = v[i].second;
        if (mulai >= now) {
            ++ans;
            now = selesai;
        }
    }

    cout << ans << '\n';
    return 0;
}
