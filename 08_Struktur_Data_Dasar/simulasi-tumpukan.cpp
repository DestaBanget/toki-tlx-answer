#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    stack<long long> st;
    long long tambah = 0;

    while (t--) {
        string s;
        cin >> s;

        if (s == "add") {
            long long x, y;
            cin >> x >> y;
            for (long long i = 0; i < y; i++) {
                st.push(x - tambah);
            }
            cout << st.size() << "\n";
        } else if (s == "rev") {
            // kosong, tidak ada operasi
        } else if (s == "del") {
            long long y;
            cin >> y;
            cout << st.top() + tambah << "\n";
            for (long long i = 0; i < y; i++) {
                st.pop();
            }
        } else if (s == "adx") {
            long long d; 
            cin >> d;
            tambah += d;
        } else if (s == "dex") {
            long long d; 
            cin >> d;
            tambah -= d;
        }
    }

    return 0;
}
