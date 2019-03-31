#include <bits/stdc++.h>
using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, f, s;
    cin >> n >> m;
    cin >> s >> f;
    s--;
    f--;

    vector<vector<pair<int, int>>> data(n, vector<pair<int, int>>());
    // vector<bool> u(n, false);
    vector<long long> d(n, 1e18);
    // vector<int> p(n);
    priority_queue <pair<int, int>> q;

    for (size_t i = 0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        data[a].push_back(make_pair(w, b));
        data[b].push_back(make_pair(w, a));
    }

    d[s] = 0;
    q.push(make_pair(0, s));

    while (!q.empty()) {
        int v = q.top().second;
        int c_d = q.top().first;
        q.pop();
        
        if (c_d > d[v]) continue;
        // u[v] = true;

        for (size_t i = 0; i<data[v].size(); i++) {
            int to = data[v][i].second, w = data[v][i].first;
            if (d[v] + w < d[to]) {
                d[to] = d[v] + w;
                // p[to] = v;
                q.push(make_pair(-1*d[to], to));
            }
        }
    }

    if (d[f] == 1e18) {
        cout << -1;
    } else {
        cout << d[f];
        // int cur = f;
        // vector<int> ans;
        // while (cur != s) {
        //     ans.push_back(cur+1);
        //     cur = p[cur];
        // }
        // ans.push_back(s+1);
        // copy(ans.rbegin(), ans.rend(), ostream_iterator<int>(cout, " "));

    }

    return 0;
}