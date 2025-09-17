#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        
        auto low = upper_bound(arr.begin(), arr.end(), x);
        auto high = upper_bound(arr.begin(), arr.end(), y);
        
        int count = high - low;
        cout << count << "\n";
    }
    
    return 0;