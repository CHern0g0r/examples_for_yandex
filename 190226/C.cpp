#include <bits/stdc++.h>
using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> data(n, vector<int>());

    for (int i = 0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        data[a].push_back(b);
        data[b].push_back(a);
    }

    long long ans = 0;
    for (int i = 0; i<n; i++) {
        vector<int> d(n, -1);
        queue<int> q;
        q.push(i);
        d[i] = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (auto x: data[cur]) {
                if (d[x] == -1) {
                    d[x] = d[cur] + 1;
                    ans += d[x];
                    q.push(x);
                }
            }
        }
    }

    cout << ans/2;

    return 0;
}
