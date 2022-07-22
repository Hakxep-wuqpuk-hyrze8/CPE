#include <bits/stdc++.h>

using namespace std;

const int mxN = 100005;
const double EPS = 1e-7;


#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define PI acos(-1.0)

class Segment {

public:
    int seg[400005], a[100005];

    void build (int l, int r, int v) {
        if (l == r) {
            seg[v] = a[l];
            return;
        }

        int mid = (l+r)/2;
        build(l, mid, v*2);
        build(mid+1, r, v*2+1);
        seg[v] = max(seg[v*2], seg[v*2+1]);
    }

    int query(int L, int R, int l, int r, int v) {

        if (l == L && r == R) {
            return seg[v];
        }

        int mid=(l+r)/2;
        if (R<=mid)
            return query(L, R, l, mid, v*2);
        else if (L>mid)
            return query(L, R, mid+1, r, v*2+1);
        else
            return max(query(L, mid, l, mid, v*2), query(mid+1, R, mid+1, r, v*2+1));
    }
};


void solve() {
    int n, q;
    while (cin >> n && n) {
        cin >> q;
        Segment sg;

        map<int, int> cnt, num, pos;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            cin >> num[i];
            if (!cnt[num[i]]) {
                v.pb(num[i]);
                pos[num[i]] = i;
            }
            cnt[num[i]]++;
        }

        int index = 1;
        for (auto e: v) {
            for (int i = 0; i < cnt[e]; i++) {
                sg.a[index++] = cnt[e];
            }
        }

        sg.build(1, n, 1);

        while (q--) {
            int ql, qr; cin >> ql >> qr;
            if (num[ql] == num[qr]) {
                cout << qr - ql + 1 << '\n';
                continue;
            }

            int left = cnt[num[ql]] - (ql - pos[num[ql]]);
            int right = qr - pos[num[qr]] + 1;

            if (pos[num[qr]] == 0 || num[pos[num[qr]] - 1] == num[ql]) {
                cout << max(left, right) << '\n';
                continue;
            }

            int leftPos = pos[num[ql]] + cnt[num[ql]];
            int rightPos = pos[num[qr]] - 1;

            int middlemx = sg.query(leftPos, rightPos, 1, n, 1);

            cout << max({middlemx, left, right}) << '\n';
        }
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while (T--)
        solve();

    return 0;
}
/*
10 3
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10
*/
