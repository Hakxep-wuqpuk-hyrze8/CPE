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
         string s; cin >> s;
         int n = (int)s.length();

         ll leftu = 0, leftd = 1, rightu = 1, rightd = 0;
         for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                leftu = leftu + rightu;
                leftd = leftd + rightd;
            } else {
                rightu = leftu + rightu;
                rightd = leftd + rightd;
            }
         }

         cout << leftu + rightu << '/' << leftd + rightd << '\n';
    }

    return 0;
}
