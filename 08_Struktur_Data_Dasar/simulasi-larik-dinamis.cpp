#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    map<int, vector<int>> mp;

    while (t--) {
        string s;
        cin >> s;

        if (s == "add") {
            int l, x, y; 
            cin >> l >> x >> y;

            for (int i = 0; i < y; i++) {
                mp[l].push_back(x);
            }
        } 
        else if (s == "new") {

        } 
        else if (s == "out") {
            int l, z;
            cin >> l >> z;

            cout << mp[l][z - 1] << "\n";
        }
    }

