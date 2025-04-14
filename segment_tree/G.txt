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

istream& operator>>(istream& in, vector<ll>& a) {
    for (ll i = 0; i < (ll)a.size(); i++) {
        in >> a[i];
    }
    return in;
}

ostream& operator<<(ostream& out, vector<ll>& a) {
    for (ll i = 0; i < (ll)a.size(); i++) {
        out << a[i] << ' ';
    }
    return out;
}

struct Node {
    int maxi = 0;
    int add = 0;
};

void pushsum(int v, int x, vector<Node>& tree) {
    tree[v].maxi += x;
    tree[v].add += x;
}

void push(int v, int l, int r, vector<Node>& tree) {
    if (r - l <= 1) {
        tree[v].add = 0;
        return;
    }
    pushsum(2 * v, tree[v].add, tree);
    pushsum(2 * v + 1, tree[v].add, tree);
    tree[v].add = 0;
}

void merge(int v, vector<Node>& tree) {
    tree[v].maxi = max(tree[2 * v].maxi, tree[2 * v + 1].maxi);
}

void addition(int v, int l, int r, int ql, int qr, int x, vector<Node>& tree) {
    if (qr <= l or ql >= r) {
        return;
    }
    if (ql <= l and r <= qr) {
        tree[v].maxi += x;
        tree[v].add += x;
        return;
    }
    int m = (l + r) / 2;
    push(v, l, r, tree);
    addition(2 * v, l, m, ql, qr, x, tree);
    addition(2 * v + 1, m, r, ql, qr, x, tree);
    merge(v, tree);
}

int get_max(int v, int l, int r, int ql, int qr, vector<Node>& tree) {
    if (l >= qr or ql >= r) {
        return 0;
    }
    if (ql <= l and r <= qr) {
        return tree[v].maxi;
    }
    int m = (l + r) / 2;
    push(v, l, r, tree);
    return max(get_max(2 * v, l, m, ql, qr, tree), get_max(2 * v + 1, m, r, ql, qr, tree));
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
    vector<Node> tree(2 * n);
    for (int i = 0; i < oldn; i++) {
        int c;
        cin >> c;
        addition(1, 0, n, i, i + 1, c, tree);
    }
    int q;
    cin >> q;
    for (int t = 0; t < q; t++) {
        char c;
        cin >> c;
        if (c == 'a') {
            int l, r, x;
            cin >> l >> r >> x;
            addition(1, 0, n, l - 1, r, x, tree);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << get_max(1, 0, n, l - 1, r, tree) << ' ';
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