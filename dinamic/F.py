#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000000; // Adjust as needed for recursion limit
vector<int> used;
vector<vector<int>> v;
vector<vector<int>> comp;

void dfs(int i, int o) {
    used[i] = 1;
    comp[o].push_back(i);
    for (int j : v[i]) {
        if (used[j] != 1) {
            dfs(j, o);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    used.resize(n, 0);
    v.resize(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
    }

    int kol_vo = 0;
    int sumka = 0;

    while (sumka != n) {
        kol_vo++;
        comp.push_back({});
        int start = find(used.begin(), used.end(), 0) - used.begin();
        dfs(start, kol_vo - 1);
        sumka += comp[kol_vo - 1].size();
    }

    cout << kol_vo;
    for (int i = 0; i < kol_vo; i++) {
        cout << "\n" << comp[i].size() << "\n";
        for (int elm : comp[i]) {
            cout<< elm + 1 << " ";
        }
    }

    return 0;
}
