#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int k;
    cin >> k;
    vector<int> p(k);
    for (int i = 0; i < k; i++) cin >> p[i];
    vector<int> c(k);
    for (int i = 0; i < k; i++) cin >> c[i];
    int n; cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(b.begin(), b.end(), greater<int>());

    vector<pair<int,int>> cages;
    for (int i = 0; i < k; i++) cages.push_back({c[i], p[i]});
    sort(cages.begin(), cages.end());

    int idx = 0, total = 0;
    for (int i = 0; i < k && idx < n; ++i) {
        int cost = cages[i].first;
        int cap = cages[i].second;
        while (cap > 0 && idx < n) {
            total += b[idx] * cost;
            ++idx;
            --cap;
        }
    }

    cout << total << '\n';
    return 0;
}
