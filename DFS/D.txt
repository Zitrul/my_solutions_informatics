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

bool dfs(int v, vector<int>& used, vector<vector<int>>& graph, int col) {
    used[v] = col;
    for (auto to : graph[v]) {
        if (used[to] == col) {
            return false;
        }
        if (!used[to]) {
            if (!dfs(to, used, graph, -col)) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> used(n, 0);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            if (!dfs(i, used, graph, 1)) {
                cout << "NO";
                return;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        if (used[i] == 1) {
            cout << i + 1 << ' ';
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