#include <bits/stdc++.h>

using namespace std;

const int mxN = 100005;
const int mxC = 10005;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define PI acos(-1.0)

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0,  1, 1};

int main()
{
    int T; cin >> T;

    while (T--) {
        int N; cin >> N;
        int a[N];
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }

        int q; cin >> q;
        bool ok;
        while (q--) {
            int L, R; cin >> L >> R;
            L--; R--;
            ok = 0;
            int c[mxC];
            for (int i = 0; i < mxC; i++) c[i] = 0;

            for (int i = L; i <= R; i++)  {
                if (!c[a[i]])
                    c[a[i]]++;
                else {
                    cout << c[a[i]] << ' ';
                    ok = 1;
                    break;
                }
            }

            if (ok) {
                cout << 0 << '\n'; continue;
            }

            int pre = 0, ans = 1e9;

            for (int i = 1; i < mxC; i++) {
                if (c[i]) {
                    if (!pre)
                        pre = i;
                    else {
                        ans = min(ans, i - pre);
                        pre = i;
                    }
                }
            }

            cout << ans << '\n';
        }
    }

    return 0;
}
