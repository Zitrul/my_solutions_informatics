#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iomanip>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& graph, vector<int>& visited, queue<int>& bfs_queue) {
    while (bfs_queue.size() > 0) {
        int cur = bfs_queue.front();
        for (int i = 0; i < graph[cur].size(); i++) {
            if (visited[graph[cur][i]] == -1) {
                bfs_queue.push(graph[cur][i]);
                visited[graph[cur][i]] = visited[cur] + 1;
            }
        }
        bfs_queue.pop();
    }
}


int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }
    vector<int> visited(n, -1);
    visited[0] = 0;
    queue<int> bfs_queue;
    bfs_queue.push(0);
    bfs(graph, visited, bfs_queue);
    int ind = 0;
    int maximum = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] > maximum) {
            maximum = visited[i];
            ind = i;
        }
    }
    visited.clear();
    visited.resize(n, -1);
    visited[ind] = 0;
    bfs_queue.push(ind);
    bfs(graph, visited, bfs_queue);
    maximum = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] > maximum) {
            maximum = visited[i];
        }
    }
    cout << maximum;
    return 0;
}