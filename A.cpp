#include <bits/stdc++.h>

using namespace std;
using vi = vector<int>;

#define ll long long
#define pb push_back

const int mod = 1e9+7;
const int mxN = 4e3+5;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

void solve() {
    int n, a[5]={1, 5, 10, 25, 50};

    int dp[8000]={0};
    dp[0]=1;

    for (int i=0; i<5; i++) {
        for (int j=a[i]; j<8000; j++) {
            dp[j] += dp[j-a[i]];
        }
    }

    while (cin >> n) {
        cout << dp[n] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T=1;
    //cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

/*
*/
