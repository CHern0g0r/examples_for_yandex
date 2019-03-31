#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, s;
    cin >> n >> s >> m;
    vector<vector<int>> x(n, vector<int>());
    vector<int> dist(n, -1);
    dist[--s] = 0;

    for (int i = 0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        x[--b].push_back(--a);
    }

    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int cur = q.front();
        // cout << "while " << cur << "\n";
        q.pop();
        // for (int i = 0; i<n; i++) {
        //     cout << dist[i] << " ";
        // }
        // cout << "\n";
        for (auto i: x[cur]) {
            if (dist[i] > dist[cur] + 1 || dist[i] == -1) {
                dist[i] = dist[cur] + 1;
                q.push(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }

}