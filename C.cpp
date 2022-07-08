#include <bits/stdc++.h>

using namespace std;

const int mxN = 100005;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define PI acos(-1.0)

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0,  1, 1};

int p[mxN], sz[mxN];

int Find (int x) {
    return x == p[x] ? x : p[x] = Find(p[x]);
}

void Union (int x, int y) {
    int Fx = Find(x), Fy = Find(y);

    if (Fx == Fy) {
        cout << sz[Fx] << '\n';
        return;
    }

    if (sz[Fx] > sz[Fy]) {
        sz[Fx] += sz[Fy];
        p[Fy] = Fx;
        cout << sz[Fx] << '\n';
    } else {
        swap(Fx, Fy);
        sz[Fx] += sz[Fy];
        p[Fy] = Fx;
        cout << sz[Fx] << '\n';
    }
}

int main()
{
    int T; cin >> T;

    while (T--) {
        for (int i = 0; i < mxN; i++) p[i] = i;
        for (int i = 0; i < mxN; i++) sz[i] = 1;
        int q; cin >> q;
        int cnt = 1;
        map<string, int> mp;
        while (q--) {
            string s, t; cin >> s >> t;
            if (!mp[s]) {
                mp[s] = cnt++;
            }
            if (!mp[t]) {
                mp[t] = cnt++;
            }

            Union(mp[s], mp[t]);
        }
    }



    return 0;
}
