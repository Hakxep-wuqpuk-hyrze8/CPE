#include <bits/stdc++.h>

using namespace std;

const int mxN = 1005;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()

/* int joe (int n, int k) {
    if (n == 1)
        return 0;

    return (joe(n-1, k) + k) % n;
} */

bool isPrime[mxN];
vector<int> prime[mxN];

struct edge{
    int u, w;
    bool operator < (const edge &cmp) const {
        return cmp.w < w;
    }
};

int dis[mxN];
vector<edge> adj[mxN];

void Dijkstra(int s) {
    memset(dis, -1, sizeof(dis));
    priority_queue<edge> pq;
    pq.push({s, 0});

    while (pq.size()) {
        auto node=pq.top(); pq.pop();
        if (dis[node.u] != -1) continue;
        dis[node.u] = node.w;
        for (auto e: adj[node.u]) {
            if (dis[e.u] == -1)
                pq.push({e.u, e.w + node.w});
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(isPrime, true, sizeof(isPrime));

    for (int i = 2; i * i < mxN; i++) {
        for (int j = i * i; j < mxN; j += i) {
            isPrime[j] = false;
        }
    }

    for (int i = 1; i < mxN; i++) {
        for (int u = 2; u < i; u++) {
            if (i % u == 0 && isPrime[u]) {
                prime[i].pb(u+i);
            }
         }
    }

    for (int i = 1; i < mxN; i++) {
        for (auto e : prime[i]) {
            adj[i].pb({e, 1});
        }
    }

    int n, m, ts=1;
    while (cin >> n >> m && n+m) {
        if (n==m) {
            cout << "Case " << ts++ << ": " << 0 << '\n';
            continue;
        }
        Dijkstra(n);
        cout << "Case " << ts++ << ": " << dis[m] << '\n';
    }

    return 0;
}
/*
*/
