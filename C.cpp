#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e9;

#define ll long long
#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define PI acos(-1.0)

int joe (int n, int k) {
    if (n == 1)
        return 0;

    return (joe(n-1, k) + k) % n;
}

int main()
{
    int T, ts=1; cin >> T;

    while (T--) {
         int n, k; cin >> n >> k;
         cout << "Case " << ts++ << ": " << joe(n, k) + 1 << '\n';
    }

    return 0;
}
