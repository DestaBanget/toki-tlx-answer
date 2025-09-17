#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    double median;
    if (N % 2 == 1) {
        median = A[N / 2];
    } else {
        median = (A[N / 2 - 1] + A[N / 2]) / 2.0;
    }

    cout << fixed << setprecision(1) << median << "\n";
    return 0;
}
