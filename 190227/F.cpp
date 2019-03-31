#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());

    for (int i = 0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        g[a].push_back(make_pair(w, b));
    }

    int k;
    cin >> k;

    for (int i = 0; i<k; i++) {

        int s, f;
        cin >> s >> f;
        s--, f--;

        if (s == f) {
            cout << 0 << endl;
            continue;
        } 

        queue<int> q[3];
        q[0].push(s);

        vector<int> d(n, -1);
        d[s] = 0;

        while (!q[0].empty() || !q[1].empty() || !q[2].empty()) {
            while (q[0].empty()) {
                q[0].swap(q[1]);
                q[1].swap(q[2]);
            }

            int cur = q[0].front();
            if (cur == f) break;
            q[0].pop();
            int dcur = d[cur]/1000;

            for (auto x: g[cur]) {
                int len = x.first;
                int to = x.second;
                if (d[to] == -1 || d[to] > d[cur] + len) {
                    int nd = -1;
                    if (d[to] != -1)
                        nd = d[to]/1000;
                    d[to] = d[cur] + len;
                    int dto = d[to]/1000;
                    if (nd != dto)
                        q[dto - dcur].push(to);
                }
            }

        }

        cout << d[f] << endl;
        // copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));
        // cout << endl;

    }

    return 0;
}