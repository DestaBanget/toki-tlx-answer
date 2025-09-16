#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<int>> vec(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    while (t--) {
        string c;
        cin >> c;

        if (c == "_") {  
            vector<vector<int>> newVec(n, vector<int>(m));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    newVec[i][j] = vec[n - i - 1][j];
                }
            }
            vec = move(newVec);
        } 
        else if (c == "|") {  
            vector<vector<int>> newVec(n, vector<int>(m));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    newVec[i][j] = vec[i][m - j - 1];
                }
            }
            vec = move(newVec);
        } 
        else if (c == "90") {  
            vector<vector<int>> newVec(m, vector<int>(n));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    newVec[j][n - i - 1] = vec[i][j];
                }
            }
            vec = move(newVec);
            swap(n, m);
        } 
        else if (c == "180") {  
            vector<vector<int>> newVec(n, vector<int>(m));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    newVec[n - i - 1][m - j - 1] = vec[i][j];
                }
            }
            vec = move(newVec);
        } 
        else if (c == "270") {  
            vector<vector<int>> newVec(m, vector<int>(n));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    newVec[m - j - 1][i] = vec[i][j];
                }
            }
            vec = move(newVec);
            swap(n, m);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
