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

vector<int> log2n;

int get_max(int l, int r, vector<vector<int>>& sparse) {
    int sz = log2n[(r - l) + 1];
    return max(sparse[sz][l - 1], sparse[sz][r - (1 << sz)]);
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    cin >> arr;
    int power = 0;
    while ((1 << power) < n) {
        power += 1;
    }
    log2n.resize(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        log2n[i] = log2n[i / 2] + 1;
    }
    vector<vector<int>> sparse(power + 1, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        sparse[0][i] = arr[i];
    }
    for (int k = 1; k <= power; k++) {
        for (int i = 0; i < n - (1 << k) + 1; i++) {
            sparse[k][i] = max(sparse[k - 1][i], sparse[k - 1][i + (1 << (k - 1))]);
        }
    }
    int q;
    cin >> q;
    for (int test = 0; test < q; test++) {
        int l, r;
        cin >> l >> r;
        cout << get_max(l, r, sparse) << ' ';
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