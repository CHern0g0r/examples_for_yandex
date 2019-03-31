#include <bits/stdc++.h>
using namespace std;

struct Edge {
    long long a, b;
    long long w;
};

const long long INF = numeric_limits<long long>::max();

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    vector<Edge> e;

    for (long long i = 0; i<n; i++) {
        for (long long j = 0; j<n; j++) {
            long long w;
            cin >> w;
            e.push_back(Edge{i, j, w});
        }
    }

    vector<long long> d(n, INF);
    vector<long long> p(n, -1);
    d[0] = 0;
    long long flag;

    for (long long i = 0; i<n; i++) {
        flag = -1;
        for (long long j = 0; j<e.size(); j++) {
            // if (d[e[j].a] < INF) {
                if (d[e[j].b] > d[e[j].a] + e[j].w) {
                    d[e[j].b] = d[e[j].a] + e[j].w;
                    p[e[j].b] = e[j].a;
                    flag = e[j].b;
                }
            // }
        }
    }

    if (flag == -1) {
        cout << "NO";
    } else {
        cout << "YES" << endl;

        vector<long long> path;
        vector<bool> was(n, false);

        long long cur = flag;

        for (long long i = 0; i<n; i++) {
            cur = p[cur];
        }

        while (!was[cur]) {
            was[cur] = 1;
            path.push_back(cur+1);
            cur = p[cur];
        }

        cout << path.size() << endl;
        copy(path.rbegin(), path.rend(), ostream_iterator<long long>(cout, " "));

    }

    return 0;
}