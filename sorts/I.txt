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
        out << it << '\n';
    }
    return out;
}

bool comp(int a, int b) {
    return a < b;
}

void mysort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (!comp(arr[j], arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void solve() {
    int c;
    vector<int> arr;
    while (cin >> c) {
        arr.push_back(c);
    }
    int mini = INF;
    int secondmin = INF;
    int maxi = -INF;
    int secondmax = -INF;
    int thirdmax = -INF;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > maxi) {
            thirdmax = secondmax;
            secondmax = maxi;
            maxi = arr[i];
        }
        else if (arr[i] > secondmax) {
            thirdmax = secondmax;
            secondmax = arr[i];
        }
        else if (arr[i] > thirdmax) {
            thirdmax = arr[i];
        }
        if (arr[i] < mini) {
            secondmin = mini;
            mini = arr[i];
        }
        else if (arr[i] < secondmin) {
            secondmin = arr[i];
        }
    }
    if (maxi < 0) {
        cout << maxi << ' ' << secondmax << ' ' << thirdmax;
        return;
    }
    if ((ll)mini * secondmin < (ll)secondmax * thirdmax) {
        cout << maxi << ' ' << secondmax << ' ' << thirdmax;
    }
    else {
        cout << maxi << ' ' << mini << ' ' << secondmin;
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