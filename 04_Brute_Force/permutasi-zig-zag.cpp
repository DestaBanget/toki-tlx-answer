#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> urut;
vector<bool> dipakai;

bool zigzag(vector<int> &a, int n) {
    if (n < 3) return true;
    for (int i = 1; i + 1 < n; i++) {
        if (!((a[i] < a[i-1] && a[i] < a[i+1]) || 
              (a[i] > a[i-1] && a[i] > a[i+1]))) {
            return false;
        }
    }
    return true;
}

void rek() {
    if ((int)urut.size() == n) {
        if (zigzag(urut, n)) {
            for (int x : urut) cout << x;
            cout << "\n";
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!dipakai[i]) {
            dipakai[i] = true;
            urut.push_back(i);
            rek();
            urut.pop_back();
            dipakai[i] = false;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    urut.clear();
    dipakai.assign(n+1, false);
    rek();
}
