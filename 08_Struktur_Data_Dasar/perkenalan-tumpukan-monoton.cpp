#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    long long res = 0;

    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && vec[st.top()] <= vec[i]) st.pop();

        if (st.empty()) res += (long long)(i + 1);
        else res += (long long)(i - st.top());

        st.push(i);
    }

    cout << res << "\n";

    return 0;
}
