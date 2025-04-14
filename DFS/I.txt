//#pragma GCC optimize("O3")
#include <vector>
#include <iostream>
#include <random>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <queue>

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

void dfs(ll v, vector<ll>& used, vector<ll>& sz, vector<ll>& sum, vector<vector<ll>>& graph) {
    used[v] = 1;
    sz[v] = 1;
    sum[v] = 1;
    for (auto to : graph[v]) {
        if (!used[to]) {
            dfs(to, used, sz, sum, graph);
            sum[v] += sum[to] + sz[to];
            sz[v] += sz[to];
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> graph(n);
    for (ll i = 1; i < n; i++) {
        ll u;
        cin >> u;
        graph[u - 1].push_back(i);
    }
    vector<ll> sz(n, 0);
    vector<ll> sum(n, 0);
    vector<ll> used(n, 0);
    dfs(0, used, sz, sum, graph);
    cout << sum;
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