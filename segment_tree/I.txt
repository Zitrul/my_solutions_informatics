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

vector<int> tree;

void upd(int v, int val) {
    tree[v] = val;
    while (v != 0) {
        v >>= 1;
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}

int get_sum(int v, int l, int r, int ql, int qr) {
    if (ql <= l and r <= qr) {
        return tree[v];
    }
    if (ql >= r or qr <= l) {
        return 0;
    }
    int m = (l + r) / 2;
    return get_sum(2 * v, l, m, ql, qr) + get_sum(2 * v + 1, m, r, ql, qr);
}

void solve() {
    int n;
    cin >> n;
    int power = 0;
    while ((1 << power) < n) {
        power += 1;
    }
    int oldn = n;
    n = (1 << power);
    tree.resize(2 * n, 0);
    for (int i = 0; i < oldn; i++) {
        int c;
        cin >> c;
        if (c == 0) {
            upd(i + n, 1);
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        cout << get_sum(1, 0, n, l, r) << ' ';
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