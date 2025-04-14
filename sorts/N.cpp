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

bool comp(int a, int b) {
    return a < b;
}

void mysort(vector<int>& arr, int x) {
    int n = arr.size();
    vector<int> cnt(110, 0);
    for (int i = 0; i < n; i++) {
        cnt[arr[i] - x] += 1;
    }
    vector<int> ans;
    for (int i = 0; i < 110; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            ans.push_back(i + x);
        }
    }
    arr = ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    cin >> arr;
    int mini = 2 * INF;
    for (int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
    }
    mysort(arr, mini);
    cout << arr;
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