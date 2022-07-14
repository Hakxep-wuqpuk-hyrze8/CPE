#include <bits/stdc++.h>

using namespace std;

const int mxN = 105;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define PI acos(-1.0)

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0,  1, 1};

vector<int> adj[mxN];

int main()
{
    int n, ts = 1;
    while (cin >> n) {
        int in[mxN] = {0};
        map<string, int> mp;
        map<int, string> tag;
        vector<int> ans;
        string s;
        int label = 1;
        for (int i = 0; i < n; i++) {
            cin >> s;
            mp[s] = label;
            tag[label++] = s;
        }

        int m; cin >> m;
        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;
            adj[mp[a]].pb(mp[b]);
            in[mp[b]]++;
        }

        queue<int> q;
        vector<int> order;

        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                if (!q.size()) {
                    ans.pb(i);
                    q.push(i);
                }
                else {
                    order.push_back(i);
                }
            }
        }

        while (q.size()) {
            int p = q.front(); q.pop();

            for (auto e : adj[p]) {
                in[e]--;
                if (in[e] == 0) {
                    order.push_back(e);
                }
            }

            if (!order.size()) continue;

            sort(all(order));
            q.push(order[0]);
            ans.pb(order[0]);

            order.erase(order.begin());
        }

        cout << "Case #" << ts++ << ": Dilbert should drink beverages in this order:";

        for (auto e : ans) {
            cout << ' ' << tag[e];
        }
        cout << ".\n\n";

        for (int i = 0; i < mxN; i++) adj[i].clear();
        ans.clear();
    }

    return 0;
}
