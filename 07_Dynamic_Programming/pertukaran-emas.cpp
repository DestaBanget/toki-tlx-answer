#include <bits/stdc++.h>
using namespace std;

int yes(int x){
    if (x == 0) return 0;
    return max(x, (yes(x/2) + yes(x/3) + yes(x/4)));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    cout << yes(n) << "\n";

    return 0;
}