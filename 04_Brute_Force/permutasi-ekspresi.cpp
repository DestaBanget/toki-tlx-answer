#include <bits/stdc++.h>
using namespace std;

string s;
set<long long> hasil;

void rek(int pos, long long jum, long long skrg, int tanda) {
    if (pos == (int)s.size()) {
        jum += tanda * skrg;
        hasil.insert(jum);
        return;
    }
    int d = s[pos] - '0';

    rek(pos+1, jum, skrg*10 + d, tanda);

    rek(pos+1, jum + tanda*skrg, d, +1);

    rek(pos+1, jum + tanda*skrg, d, -1);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    s = to_string(n);

    int d = s[0]-'0';
    rek(1, 0, d, +1);

    cout << hasil.size() << "\n";
    return 0;
}
