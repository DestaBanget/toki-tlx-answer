#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> koin(n, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> koin[i];
    }

    int x; cin >> x;

    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int c : koin) {
            if (i - c >= 0 && dp[i-c] != INT_MAX) {
                dp[i] = min(dp[i], dp[i-c] + 1);
            }
        }
    }

    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << "\n";

    return 0;
}
