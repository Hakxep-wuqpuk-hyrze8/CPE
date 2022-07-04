#include <bits/stdc++.h>

using namespace std;

const int mxN = 25;

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

int fx[6] = {0, 1, 1, 0, -1, -1};
int fy[6] = {1, 0, -1, -1, 0, 1};

int dx[6] = {1, 1, 0, -1, -1, 0};
int dy[6] = {0, -1, -1, 0, 1, 1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<int, pair<int, int>> ans;

    queue<pair<int, int>> q;
    map<pair<int, int>, int> mp;

    mp[{0, 0}] = 1;
    int t=2;
    for (int i = 0; i < 6; i++) {
        q.push({dy[i], dx[i]});
        mp[{dy[i], dx[i]}] = 1;
        ans[t++] = {dy[i], dx[i]};
    }

    bool ok = 0;
    int tag = 8;
    while (q.size()) {
        auto p=q.front(); q.pop();
        //cout << p.F << ' ' << p.S << '\n';
        if (p.F >= 0 && p.S == 1) {
            for (int i = 0; i < 6; i++) {
                int y = p.F + fy[i];
                int x = p.S + fx[i];

                if (!mp[{y, x}]) {
                    mp[{y, x}] = 1;
                    ans[tag] = {y, x};
                    tag++;
                    q.push({y, x});
                }
            }
        }
        else {
            for (int i = 0; i < 6; i++) {
                int y = p.F + dy[i];
                int x = p.S + dx[i];

                if (!mp[{y, x}]) {
                    mp[{y, x}] = 1;
                    ans[tag] = {y, x};
                    tag++;
                    q.push({y, x});
                }
            }
        }

        if (tag > 100005) break;
    }


    int N;
    while (cin >> N) {
        cout << ans[N].F << ' ' << ans[N].S << '\n';
    }

    return 0;
}
