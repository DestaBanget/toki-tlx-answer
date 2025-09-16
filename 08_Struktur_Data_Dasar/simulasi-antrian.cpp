#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    deque<int> dq;
    bool rev = false;

    while (t--) {
        string s;
        cin >> s;

        if (s == "add") {
            int x, y; 
            cin >> x >> y;
            for (int i = 0; i < y; i++) {
                if (!rev) dq.push_back(x);
                else dq.push_front(x);
            }
            cout << dq.size() << "\n";
        } else if (s == "rev") {
            rev = !rev;
        } else if (s == "del") {
            int y;
            cin >> y;
            if (rev) cout << dq.back() << "\n";
            else cout << dq.front() << "\n";
            for (int i = 0; i < y; i++) {
                if (rev) dq.pop_back();
                else dq.pop_front();
            }
        }
    }

    return 0;
}