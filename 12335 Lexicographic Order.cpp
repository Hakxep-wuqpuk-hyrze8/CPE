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
    int T, ts=1; cin >> T;

    while (T--) {
        string s; ll k;
        cin >> s >> k;
        int n = (int)s.length();
        vector<char> v(n+1, '.');
        ll total = 1, index = 0;
        for (int i = 1; i <= n; i++) total *= i;

        for (int i = n; i >= 1; i--) {
            ll cut = total / i;
            ll pos = k / cut + (k % cut != 0);
            ll tpos = pos;
            //printf("%d ", pos);

            for (int i = 1; i <= n; i++) {
                if (v[i] == '.')
                    pos--;
                if (!pos) {
                    v[i] = s[index++];
                    break;
                }
            }

            k -= cut * (tpos - 1);
            total = total / i;
        }

        cout << "Case " << ts++ << ": ";
        for (int i = 1; i <= n; i++) {
            cout << v[i];
        }
        cout << '\n';
    }

    return 0;
}
