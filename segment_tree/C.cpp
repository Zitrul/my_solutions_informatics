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

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void upd(int v, int x, vector<int>& tree) {
    tree[v] = x;
    v >>= 1;
    while (v != 0) {
        tree[v] = gcd(tree[2 * v], tree[2 * v + 1]);
        v >>= 1;
    }
    return;
}

int get_max(int v, int l, int r, int ql, int qr, vector<int>& tree) {
    if (r <= ql or l >= qr) {
        return 0;
    }
    if (ql <= l and qr >= r) {
        return tree[v];
    }
    int m = (l + r) / 2;
    return gcd(get_max(2 * v, l, m, ql, qr, tree), get_max(2 * v + 1, m, r, ql, qr, tree));
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
    vector<int> tree(2 * n, 0);
    for (int i = 0; i < oldn; i++) {
        upd(n + i, arr[i], tree);
    }
    int q;
    cin >> q;
    for (int test = 0; test < q; test++) {
        char c;
        cin >> c;
        if (c == 's') {
            int l, r;
            cin >> l >> r;
            cout << get_max(1, 0, n, l - 1, r, tree) << ' ';
        
        }
        else {
            int ind, x;
            cin >> ind >> x;
            upd(ind - 1 + n, x, tree);
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