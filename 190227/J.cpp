#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b;
    long long w;
};

const long long INF = numeric_limits<long long>::max();

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, s;
    cin >> n >> m >> s;
    s--;

    vector<Edge> e;

    for (int i = 0; i<m; i++) {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        a--, b--;

        e.push_back(Edge{a, b, w});
    }

    vector<long long> d(n, INF);
    d[s] = 0;
    vector<bool> u(n);

    for (int i = 0; i<n*3; i++) {
        for (int j = 0; j<m; j++) {
            u[e[j].b] = u[e[j].b] | u[e[j].a];

            if (d[e[j].a] == INF) continue;

            if (d[e[j].b] == INF || d[e[j].b] > d[e[j].a] + e[j].w) {

                d[e[j].b] = d[e[j].a] + e[j].w;
                d[e[j].b] = max(d[e[j].b], -2001ll * (long long)(1e15));

                if (i > n - 1) {
                    u[e[j].b] = 1;
                }
            }
        }
    }

    for (int i = 0; i<n; i++) {
        if (u[i]) {
            cout << "-\n";
        } else if (d[i] == INF) {
            cout << "*\n";
        } else {
            cout << d[i] << endl;
        }
    }

    return 0;
}