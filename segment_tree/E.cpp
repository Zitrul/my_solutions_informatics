//#pragma GCC optimize("O3")
#include <vector>
#include <iostream>
#include <random>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;
using ushort = unsigned short;
const ll INF2 = 90000000000000;
const ll INF = 1000000001;
const ll MOD = 1000000007;

mt19937 rnd(0);

istream& operator>>(istream& in, vector<int>& a) {
    for (ll i = 0; i < (ll)a.size(); i++) {
        in >> a[i];
    }
    return in;
}

ostream& operator<<(ostream& out, vector<int>& a) {
    for (ll i = 0; i < (ll)a.size(); i++) {
        out << a[i] << ' ';
    }
    return out;
}

int bin_search(int l, int r, int i, vector<int>& prefs) {
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (prefs[m] < i) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    cin >> arr;
    vector<int> prefs = { 0 };
    for (int i = 0; i < n; i++) {
        prefs.push_back(prefs.back() + (arr[i] == 0));
    }
    int q;
    cin >> q;
    for (int t = 0; t < q; t++) {
        int i;
        cin >> i;
        int ans = bin_search(0, n + 1, i, prefs);
        if (ans == n + 1) {
            cout << -1 << ' ';
        }
        else {
            cout << ans << ' ';
        }
    }
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