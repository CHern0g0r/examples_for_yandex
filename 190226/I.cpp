#include <bits/stdc++.h>
using namespace std;

int main() {

    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<double>> g(n, vector<double>(n, -1));

    for (int i = 0; i<n; i++) {
        g[i][i] = 0;
    }

    for (int i = 0; i<m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        g[a][b] = w/100.;
    }

    for (int i = 0; i<n; i++) {
        for (int v = 0; v<n; v++) {
            for (int u = 0; u<n; u++) {
                if (g[v][i] != -1 && g[i][u] != -1 && (g[v][u] == -1 || g[v][u] > g[v][i] + g[i][u])) {
                    g[v][u] = g[v][i] + g[i][u];
                }
            }
        }
    }

    int k;
    cin >> k;
    
    for (int i = 0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        cout << g[--a][--b]*100 << "\n";
    }

    // for (int i = 0; i<n; i++) {
    //     for (int j = 0; j<n; j++) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}