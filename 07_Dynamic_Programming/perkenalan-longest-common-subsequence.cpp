#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    vector<int> atas(n), bawah(n);
    for (int i = 0; i < n; i++) cin >> atas[i];
    for (int i = 0; i < n; i++) cin >> bawah[i];

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (atas[i-1] == bawah[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[n][n] << "\n";

    return 0;
}