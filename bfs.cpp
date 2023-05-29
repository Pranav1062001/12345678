#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

const int N = 1e5 + 5;
vector<int> g[N];
bool vis[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        #pragma omp parallel for
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
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
    bfs(s);
    cout << "The result of traversal:\n";
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            cout << i << " ";
    }
    cout << endl;

    return 0;
}

