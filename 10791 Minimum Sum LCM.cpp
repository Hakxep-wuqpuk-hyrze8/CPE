#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e9;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()

ll divide (ll n) {
    if (n == 1) return 1;
    ll mn = n;
    for (ll i = 2; i <= sqrt(n); i++) {
        if (n%i == 0 && n == (i * (n / i) * __gcd(i, n / i)))
            mn = min(mn, divide(i) + divide(n/i));
    }

    return mn;
}

int main()
{
    ll N;
    int T, ts=1;

    while (cin >> N && N) {
        ll ans = divide(N);
        if (ans == N)
            ans = N + 1;
        cout << "Case " << ts++ << ": " << ans << '\n';
    }

    return 0;
}
