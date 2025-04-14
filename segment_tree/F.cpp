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

pair<int, int> merge(pair<int, int> l, pair<int, int> r) {
    if (l.first == r.first) {
        return { l.first, l.second + r.second };
    }
    return max(l, r);
}

pair<int, int> get_max(int v, int l, int r, int ql, int qr, vector<pair<int, int>>& tree) {
    if (r <= ql or l >= qr) {
        return { 0, 1 };
    }
    if (ql <= l and r <= qr) {
        return tree[v];
    }
    int m = (l + r) / 2;
    return merge(get_max(2 * v, l, m, ql, qr, tree), get_max(2 * v + 1, m, r, ql, qr, tree));
}

void upd(int v, int x, vector<pair<int, int>>& tree) {
    tree[v] = { x, 1 };
    v >>= 1;
    while (v != 0) {
        tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
        v >>= 1;
    }
    return;
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
    int oldn = n;
    n = (1 << power);
    vector<pair<int, int>> tree(2 * n, { 0, 1 });
    for (int i = 0; i < oldn; i++) {
        upd(i + n, arr[i], tree);
    }
    int q;
    cin >> q;
    for (int t = 0; t < q; t++) {
        int l, r;
        cin >> l >> r;
        pair<int, int> ans = get_max(1, 0, n, l - 1, r, tree);
        cout << ans.first << ' ' << ans.second << '\n';
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