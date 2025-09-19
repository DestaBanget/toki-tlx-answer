#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, b;
    cin >> n >> b;

    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    }

    sort(vec.rbegin(), vec.rend());

    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sum += vec[i];
        ans++;
        if (sum >= b) {
            break;
        }
    }
    cout << ans << "\n";

    return 0;
}
