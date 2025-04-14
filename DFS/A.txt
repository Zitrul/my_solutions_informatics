#include <iostream>
#include <vector>
using namespace std;

vector<int> visited;
int counter;
long long n;

void dfs(int u, vector<vector<int>> &graph) {
    visited[u] = 1;
    counter += 1;
    for (int v = 0; v < graph[u - 1].size(); v++) {
        if (graph[u - 1][v] == 0) {
            continue;
        }
        else if (visited[v + 1] == 0){
            dfs(v + 1, graph);
        }
    }
}

int main() {
    long long s;
    cin >> n >> s;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            graph[i][j] = a;
        }
    }
    for (int i = 0; i < n + 1; i++) {
        visited.push_back(0);
    }
    dfs(s, graph);
    cout << counter;
    return 0;
}