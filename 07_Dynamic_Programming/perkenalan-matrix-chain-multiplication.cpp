#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = LLONG_MAX;
const int MOD = 26101991;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> dim(n+1);
    for (int i = 0; i <= n; i++) cin >> dim[i];
    int q;
    cin >> q;

    // dp buat min cost
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    // cara buat jumlah cara yang capai min cost
    vector<vector<int>> caraMin(n+1, vector<int>(n+1, 0));
    // cara buat total semua cara
    vector<vector<int>> caraTotal(n+1, vector<int>(n+1, 0));

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
        caraMin[i][i] = 1;
        caraTotal[i][i] = 1;
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            dp[i][j] = INF;
            caraMin[i][j] = 0;
            caraTotal[i][j] = 0;

            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dim[i-1] * dim[k] * dim[j];

                // semua cara
                caraTotal[i][j] = (caraTotal[i][j] + (caraTotal[i][k] * caraTotal[k+1][j]) % MOD) % MOD;

                // min cost
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    caraMin[i][j] = (caraMin[i][k] * caraMin[k+1][j]) % MOD;
                } else if (cost == dp[i][j]) {
                    caraMin[i][j] = (caraMin[i][j] + (caraMin[i][k] * caraMin[k+1][j]) % MOD) % MOD;
                }
            }
        }
    }

    if (q == 1) cout << dp[1][n] << "\n";
    else if (q == 2) cout << caraMin[1][n] % MOD << "\n";
    else cout << caraTotal[1][n] % MOD << "\n";

    return 0;
}
