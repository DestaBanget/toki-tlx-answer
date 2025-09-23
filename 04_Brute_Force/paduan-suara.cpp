#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m;
    cin >> m;
    vector<int> tinggi(m);
    for (int i = 0; i < m; i++) cin >> tinggi[i];
    int n; cin >> n;

    sort(tinggi.begin(), tinggi.end());

    vector<int> nilai_unik;
    vector<int> jumlah_blok;
    for (int i = 0; i < m; ) {
        int j = i;
        while (j < m && tinggi[j] == tinggi[i]) j++;
        nilai_unik.push_back(tinggi[i]);
        jumlah_blok.push_back(j - i);
        i = j;
    }

    int kblok = (int)nilai_unik.size();
    vector<int> pref(kblok + 1, 0);
    for (int i = 0; i < kblok; i++) pref[i+1] = pref[i] + jumlah_blok[i];

    vector<int> lokasi_prefiks(m + 1, -1);
    for (int i = 0; i <= kblok; i++) lokasi_prefiks[pref[i]] = i;

    int q = m / n;
    int sisa = m % n;

    int maxmask = 1 << n;
    for (int mask = 0; mask < maxmask; mask++) {
        if (__builtin_popcount((unsigned)mask) != sisa) continue;
        int pos = 0;
        bool valid = true;
        vector<int> batas_pref; 
        for (int g = 0; g < n; g++) {
            int ukuran = q + ((mask >> g) & 1);
            pos += ukuran;
            if (g < n-1) {
                if (pos < 1 || pos > m-1) { valid = false; break; }
                if (lokasi_prefiks[pos] == -1) { valid = false; break; }
                batas_pref.push_back(pos);
            } else {
                if (pos != m) { valid = false; break; }
            }
        }
        if (!valid) continue;

        for (int i = 0; i < (int)batas_pref.size(); i++) {
            if (i) cout << ' ';
            int p = batas_pref[i];
            int idxblok = lokasi_prefiks[p]; 
            int nilai_batas = nilai_unik[idxblok - 1] + 1;
            cout << nilai_batas;
        }
        cout << '\n';
        return 0;
    }

    return 0;
}
