#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // for (auto val : a) cout << val << " "; cout << "\n";
    // for (auto val : b) cout << val << " "; cout << "\n";

    int i = 0, j = 0;
    int res = 0;
    while (i < n && j < m) {
        if (a[i] == b[j] || a[i] == b[j] - 1) {
            
            // if (a[i] == b[j]) cout << a[i] << " - " << b[j] << "\n";
            // if (a[i] == b[j] - 1) cout << a[i] << " - " << b[j] << "\n";
            res++;
            i++;
            j++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }

    cout << res << "\n";
    return 0;
}
