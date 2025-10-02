#include <bits/stdc++.h>
using namespace std;
#define int long long

int binom(int n, int k) {
    int res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    int m = n / 2;
    int catalan = binom(2 * m, m) / (m + 1);
    cout << catalan << "\n";
    
    return 0;
}
