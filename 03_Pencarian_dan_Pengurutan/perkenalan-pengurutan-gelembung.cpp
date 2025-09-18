#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3,unroll-loops")
#define ll long long
#define ct cout <<
#define en << "\n"

#define FOR(i, start, n) for(int i = start; i < n; i++)
#define RFOR(i, start, n) for(int i = start; i >= n; i--)
#define ci cin >>
#define All(x) x.begin(), x.end()
#define Sort(x) sort(All(x))
#define RSort(x) sort(x.rbegin(), x.rend());
#define Reverse(x) reverse(All(x))
#define InputVec0(vec, n) FOR(i, 0, n) ci vec[i];
#define InputVec1(vec, n) FOR(i, 1, n+1) ci vec[i];
#define PrintVector(vec) for(auto &val : vec) ct val << " "; ct "\n";

#define pb push_back
#define pii pair<int,int>
#define piii pair<pii,int>
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vvi vector<vector<int>>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vpii vector<pii>
#define si set<int>
#define ms multiset<int>
#define tiii tuple<int, int, int> 

//#define int ll 

using namespace std;






signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("x.in", "r", stdin);
    //freopen("x.out", "w", stdout);

    int n;
    ci n;

    vi vec(n, 0);

    FOR(i, 0, n){
        int a; ci a;
        if(i==0){
            vec[0] = a;
        } else {
            vec[i] = vec[i-1] + a;
        }
    }

    int q;
    ci q;

    while(q--){
        int x; ci x;

        int ans = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
        ans++;
        ct ans en;
    }

    return 0;
}