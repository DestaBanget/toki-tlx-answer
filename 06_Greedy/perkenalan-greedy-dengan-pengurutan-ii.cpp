#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    vector<long long> vec1(n), vec2(n);
    for (int i = 0; i < n; i++) cin >> vec1[i];
    for (int i = 0; i < n; i++) cin >> vec2[i];

    sort(vec1.begin(), vec1.end());               
    sort(vec2.begin(), vec2.end(), greater<>());  

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += vec1[i] * vec2[i];
    }

    cout << sum << "\n";
    return 0;
}
