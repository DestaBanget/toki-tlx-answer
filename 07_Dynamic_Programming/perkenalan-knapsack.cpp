#include <bits/stdc++.h>
using namespace std;

#define ct cout <<
#define en << "\n"
#define FOR(i, start, n) for(int i = start; i < n; i++)

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k; cin >> n >> k;
    swap(n, k);

    vector<int> w(n+1), v(n+1);
    FOR(i, 1, n+1) cin >> w[i] >> v[i];

    vector<vector<int>> dpVal(n+1, vector<int>(k+1, 0));
    vector<vector<int>> dpW(n+1, vector<int>(k+1, 0));
    vector<vector<int>> dpMinIdx(n+1, vector<int>(k+1, INT_MAX));
    vector<vector<bool>> take(n+1, vector<bool>(k+1, false));

    dpMinIdx[0][0] = INT_MAX;

    FOR(i, 1, n+1){
        FOR(j, 0, k+1){
            // tidak ambil i
            dpVal[i][j] = dpVal[i-1][j];
            dpW[i][j]   = dpW[i-1][j];
            dpMinIdx[i][j] = dpMinIdx[i-1][j];
            take[i][j] = false;
            
            // ambil i
            if(j - w[i] >= 0){
                int candVal = v[i] + dpVal[i-1][j - w[i]];
                int candW   = w[i] + dpW[i-1][j - w[i]];
                int candMin = min(i, dpMinIdx[i-1][j - w[i]]);

                if(candVal > dpVal[i][j] || 
                   (candVal == dpVal[i][j] && candW < dpW[i][j]) ||
                   (candVal == dpVal[i][j] && candW == dpW[i][j] && candMin < dpMinIdx[i][j])) {
                    dpVal[i][j] = candVal;
                    dpW[i][j]   = candW;
                    dpMinIdx[i][j] = candMin;
                    take[i][j] = true; // tandai kalau item i diambil
                }
            }
        }
    }

    //ct dpVal[n][k] << " " << dpW[n][k] en;

    // backtrack
    int j = k;
    vector<int> ambil;
    for(int i = n; i >= 1; i--){
        if(take[i][j]) {
            ambil.push_back(i);
            j -= w[i];
        }
    }
    reverse(ambil.begin(), ambil.end());

    for(int id : ambil) ct id << " ";
    ct "" en;

    return 0;
}
