//#pragma GCC optimize("O3")
#include <vector>
#include <iostream>
#include <random>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
using ll = long long;
using ld = long double;
using ushort = unsigned short;
const ll INF2 = 9e18;
const ll INF = 1000000001;
const ll MOD = 1000000007;

mt19937 rnd(11);

template<typename T>
istream& operator>>(istream& in, pair<T, T>& a) {
    in >> a.first >> a.second;
    return in;
}

template<typename T>
istream& operator>>(istream& in, vector<T>& a) {
    for (auto& it : a) {
        in >> it;
    }
    return in;
}

template<typename T>
ostream& operator<<(ostream& out, vector<T>& a) {
    for (auto it : a) {
        out << it << ' ';
    }
    return out;
}

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1, 0);
    int c;
    while (cin >> c) {
        if (c > n) {
            continue;
        }
        cnt[c] += 1;
    }
    int maxi = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > maxi) {
            maxi = cnt[i];
            ans = { i };
        }
        else if (cnt[i] == maxi) {
            ans.push_back(i);
        }
    }
    if (maxi == 0) {
        return;
    }
    cout << ans;
}

void precalc() {

}

signed main() {
    srand(0);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precalc();
    ll t_ = 1;
    //cin >> t_;
    ll i = 0;
    while (i != t_) {
        solve();
        i++;
    }
}