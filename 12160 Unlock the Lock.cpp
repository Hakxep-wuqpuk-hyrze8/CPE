#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e9;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define PI acos(-1.0)

int main()
{
    int origin, target, k, ts = 1;

    while (cin >> origin >> target >> k && origin + target + k) {
        int v[k];
        for (int i = 0; i < k; i++) {
            cin >> v[i];
        }

        int path[10000] = {0};
        queue<int> q;
        q.push(origin);

        while (q.size()) {
            int p = q.front(); q.pop();

            for (int i = 0; i < k; i++) {
                int nxt = p + v[i];
                nxt %= 10000;
                if (!path[nxt]) {
                    path[nxt] = path[p] + 1;
                    q.push(nxt);
                }
            }
        }

        cout << "Case " << ts++ << ": ";
        if (path[target])
            cout << path[target] << '\n';
        else
            cout << "Permanently Locked\n";
    }

    return 0;
}
