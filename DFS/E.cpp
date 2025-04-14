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

vector<pair<int, int>> mover = { {0, -1}, {0, 1}, {1, 0}, {-1, 0} };
int n, m;

bool dfs(int i, int j, vector<vector<int>>& used, vector<vector<int>>& arr) {
    used[i][j] = 1;
    for (auto [dx, dy] : mover) {
        if ((i + dx < 0) or (i + dx >= n) or (j + dy < 0) or (j + dy >= m)) {
            continue;
        }
        if (arr[i + dx][j + dy] == 1) {
            if (!used[i + dx][j + dy]) {
                dfs(i + dx, j + dy, used, arr);
            }
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                arr[i][j] = 1;
            }
        }
    }
    vector<vector<int>> used(n, vector<int>(m, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!used[i][j] and arr[i][j] == 1) {
                cnt += 1;
                dfs(i, j, used, arr);
            }
        }
    }
    cout << cnt;
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