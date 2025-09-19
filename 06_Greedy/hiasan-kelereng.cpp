#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'A']++;

    int ans = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            for (int k = j + 1; k < 26; k++) {
                int m = min({freq[i], freq[j], freq[k]});
                int sisa = 0;
                if (freq[i] > m) sisa++;
                if (freq[j] > m) sisa++;
                if (freq[k] > m) sisa++;
                sisa = min(sisa, 2);
                ans = max(ans, 3*m + sisa);
            }
        }
    }

    if (ans < 3) cout << -1 << "\n";
    else cout << ans << "\n";

    return 0;
}
