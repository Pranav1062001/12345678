#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
bool vis[N];

void dfs(int u) {
    vis[u] = true;

    #pragma omp parallel for
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!vis[v])
            dfs(v);
    }
}

int main() {
    int n, m, s;
    cout<<"Enter number of vertices, edges and Starting vertex: ";
    cin >> n >> m >> s;

    for (int i = 0; i < m; i++) {
        int x, y;
        cout<<"Enter vertex and its edge: ";
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(s);
    cout << "The result of traversal:\n";
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            cout << i << " ";
    }
    cout << endl;

    return 0;
}

