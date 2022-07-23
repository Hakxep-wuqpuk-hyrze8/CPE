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

    void init() {
        memset(seg, 1, sizeof(seg));
    }

    void build (int l, int r, int v) {
        if (l == r) {
            seg[v] = a[l];
            return;
        }

        int mid = (l+r)/2;
        build(l, mid, v*2);
        build(mid+1, r, v*2+1);
        seg[v] = seg[v*2] * seg[v*2+1];
    }

    ll query(int L, int R, int l, int r, int v) {
        if (l == L && r == R) {
            return seg[v];
        }

        int mid=(l+r)/2;
        if (R<=mid)
            return query(L, R, l, mid, v*2);
        else if (L>mid)
            return query(L, R, mid+1, r, v*2+1);
        else
            return query(L, mid, l, mid, v*2) * query(mid+1, R, mid+1, r, v*2+1);
    }

    void update (int pos, int val, int l, int r, int v) {

        if (l == r) {
            seg[v] = val;
            return;
        }

        int mid=(l+r)/2;
        if (pos<=mid)
            update(pos, val, l, mid, v*2);
        else
            update(pos, val, mid+1, r, v*2+1);

        seg[v] = seg[v*2] * seg[v*2+1];
    }
};

void solve() {
    int n, q;
    while (cin >> n >> q) {
        Segment sg;
        sg.init();

        string ans = "";

        for (int i = 1; i <= n; i++) {
            int k; cin >> k;
            if (k > 0) sg.a[i] = 1;
            else if (k < 0) sg.a[i] = -1;
            else sg.a[i] = 0;
        }

        sg.build(1, n, 1);

        while (q--) {
            char ch; cin >> ch;

            if (ch == 'C') {
                int pos, val; cin >> pos >> val;

                if (val > 0) val = 1;
                else if (val < 0) val = -1;

                sg.update(pos, val, 1, n, 1);
            }
            else {
                int ql, qr; cin >> ql >> qr;
                int total = sg.query(ql, qr, 1, n, 1);

                if (total > 0) {
                    ans += '+';
                }
                else if (total < 0) {
                    ans += '-';
                }
                else {
                    ans += '0';
                }
            }
        }

        cout << ans << '\n';
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
