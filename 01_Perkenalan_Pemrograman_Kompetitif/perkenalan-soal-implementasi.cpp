#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = n - 1; j >= 0; j--) {
            cout << vec[j][i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
