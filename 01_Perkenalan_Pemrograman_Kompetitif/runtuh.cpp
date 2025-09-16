#include <bits/stdc++.h>
using namespace std;

int baris, kolom, terakhirPenuh;

void bacaPapan(vector<vector<char>> &papan) {
    for (int r = 0; r < baris; r++) {
        for (int c = 0; c < kolom; c++) {
            cin >> papan[r][c];
        }
    }
}

vector<bool> cekPenuh(const vector<vector<char>> &papan) {
    vector<bool> penuh(baris, true);
    for (int r = 0; r < baris; r++) {
        for (int c = 0; c < kolom; c++) {
            if (papan[r][c] == '0') {
                penuh[r] = false;
                break;
            }
        }
    }
    return penuh;
}

bool hapusBaris(vector<vector<char>> &papan, const vector<bool> &penuh) {
    bool ada = false;
    for (int r = 0; r < baris; r++) {
        if (penuh[r]) {
            for (int c = 0; c < kolom; c++) {
                papan[r][c] = '0';
            }
            terakhirPenuh = r;
            ada = true;
        }
    }
    return ada;
}

void cariPosisiAkhir(const vector<vector<char>> &papan, vector<int> &pos) {
    for (int c = 0; c < kolom; c++) {
        int k = terakhirPenuh + 1;
        pos[c] = terakhirPenuh;
        while (k < baris && papan[k][c] != '1') {
            pos[c]++;
            k++;
        }
    }
}

void jatuhkan(vector<vector<char>> &papan, vector<int> &pos) {
    for (int c = 0; c < kolom; c++) {
        for (int r = pos[c]; r >= 0; r--) {
            if (papan[r][c] == '1') {
                papan[r][c] = '0';
                papan[pos[c]][c] = '1';
                pos[c]--;
            }
        }
    }
}

void cetakPapan(const vector<vector<char>> &papan) {
    for (int r = 0; r < baris; r++) {
        for (int c = 0; c < kolom; c++) {
            cout << papan[r][c];
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> baris >> kolom;

    vector<vector<char>> papan(baris, vector<char>(kolom));
    bacaPapan(papan);

    bool selesai = true;
    vector<int> posisi(kolom);

    while (selesai) {
        auto penuh = cekPenuh(papan);
        selesai = hapusBaris(papan, penuh);
        if (!selesai) break;
        cariPosisiAkhir(papan, posisi);
        jatuhkan(papan, posisi);
    }

    cetakPapan(papan);

    return 0;
}
